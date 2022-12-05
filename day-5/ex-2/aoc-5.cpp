#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

typedef std::vector<char> Stack;
typedef std::vector<Stack> Stacks;

enum class Parser { CRATE, MOVEMENT };

Parser crateParser(std::string line, Stacks &stacks) {
  // every 4 characters is a crate
  for (auto i = 0; i < line.size(); i += 4) {
    int stack = i / 4;
    char crate = line[i + 1];
    if (crate == ' ') {
      continue;
    } else if (isdigit(crate)) {
      return Parser::MOVEMENT;
    }
    stacks[stack].insert(stacks[stack].begin(), crate);
  }
  return Parser::CRATE;
}

void movementParser(std::string line, Stacks &stacks) {
  int crate_amount, original_stack, target_stack;
  sscanf(line.c_str(), "move %d from %d to %d", &crate_amount, &original_stack, &target_stack);
  // both stacks are 0-indexed
  original_stack--;
  target_stack--;
  Stack moved;
  for (auto i = 0; i < crate_amount; i++) {
    moved.insert(moved.begin(), stacks[original_stack].back());
    stacks[original_stack].pop_back();
  }
  stacks[target_stack].insert(stacks[target_stack].end(), moved.begin(), moved.end());
}

int main() {
  std::ifstream input("aoc-5-input.txt");
  std::string line;
  int i = 0;
  Stacks stacks(9); // yes this is hardcoded
  Parser parsing = Parser::CRATE;
  while (std::getline(input, line)) {
    if (parsing == Parser::CRATE) {
      parsing = crateParser(line, stacks);
      continue;
    }
    movementParser(line, stacks);
  }

  for (auto stack : stacks) {
    std::cout << stack.back();
  }
  std::cout << std::endl;
  return 0;
}