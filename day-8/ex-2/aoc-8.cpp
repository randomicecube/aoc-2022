#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define ROTATIONS 3

struct Tree {
  int height;
  int score = 1;
};

void rotateMatrix(std::vector<std::vector<Tree>> &matrix) {
  int rowLength = matrix[0].size();
  int colLength = matrix.size();
  std::vector<std::vector<Tree>> rotatedMatrix;
  for (int i = 0; i < rowLength; i++) {
    std::vector<Tree> newRow;
    for (int j = colLength - 1; j >= 0; j--) {
      newRow.push_back(matrix[j][i]);
    }
    rotatedMatrix.push_back(newRow);
  }
  matrix = rotatedMatrix;
}

void directionScenicScore(std::vector<std::vector<Tree>> &forest) {
  int rowLength = forest[0].size();
  for (std::vector<Tree> &row : forest) {
    for (int i = rowLength - 1; i >= 0; i--) {
      bool found = false;
      for (int j = i - 1; j >= 0; j--) {
        if (row[j].height >= row[i].height) {
          row[i].score *= (i - j);
          found = true;
          break;
        }
      }
      if (!found) {
        row[i].score *= i;
      }
    }
  }
}

int main() {
  std::ifstream input("resources/aoc-input.txt");
  std::string line;
  std::vector<std::vector<Tree>> forest;
  while (std::getline(input, line)) {
    std::vector<Tree> row;
    for (auto c : line) {
      row.push_back(Tree{c - '0'});
    }
    forest.push_back(row);
  }

  for (int i = 0; i <= ROTATIONS; i++) {
    directionScenicScore(forest);
    rotateMatrix(forest);
  }

  int score = 0;
  for (std::vector<Tree> &row : forest) {
    for (Tree &tree : row) {
      if (tree.score > score) {
        score = tree.score;
      }
    }
  }

  std::cout << "Score: " << score << std::endl;
  return 0;
}