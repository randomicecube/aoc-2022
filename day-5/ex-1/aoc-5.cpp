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
  int line_size = line.size();
  for (int i = 0; i < line_size; i += 4) {
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
  for (int i = 0; i < crate_amount; i++) {
    stacks[target_stack].push_back(stacks[original_stack].back());
    stacks[original_stack].pop_back();
  }
}

int main() {
  std::ifstream input("resources/aoc-5-input.txt");
  std::string line;
  Stacks stacks(9); // yes this is hardcoded
  Parser parsing = Parser::CRATE;
  while (std::getline(input, line)) {
    if (line.empty()) {
      continue;
    }
    if (parsing == Parser::CRATE) {
      parsing = crateParser(line, stacks);
      continue;
    }
    movementParser(line, stacks);
  }

  for (Stack stack : stacks) {
    std::cout << stack.back();
  }
  std::cout << std::endl;
  return 0;
}