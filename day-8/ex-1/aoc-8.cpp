#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define ROTATIONS 3

struct Tree {
  int height;
  bool seen = false;
};

// Debug function to print matrix, ignore
void printMatrix(std::vector<std::vector<Tree>> forest) {
  // Print forest
  for (std::vector<Tree> &row : forest) {
    for (Tree &tree : row) {
      if (!tree.seen) {
        std::cout << tree.height;
        continue;
      }
      std::cout << "X";
    }
    std::cout << std::endl;
  }
  std::cout << "---";
}

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

int directionScore(std::vector<std::vector<Tree>> &forest) {
  int score = 0;
  for (std::vector<Tree> &row : forest) {
    int highestTree = -1;
    for (Tree &tree : row) {
      if (tree.height > highestTree) {
        highestTree = tree.height;
        if (!tree.seen) {
          tree.seen = true;
          score++;
        }
      }
    }
  }
  return score;
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

  int score = 0;
  for (int i = 0; i <= ROTATIONS; i++) {
    score += directionScore(forest);
    rotateMatrix(forest);
  }

  std::cout << "Score: " << score << std::endl;
  return 0;
}