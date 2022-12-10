#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#define SCREEN_WIDTH 40
std::map<std::string, int> instructionCycles = {{"addx", 2}, {"noop", 1}};

inline char writePixel(int X, int cycle) {
  const int column = (cycle - 1) % SCREEN_WIDTH;
  if (std::abs(X - column) <= 1) {
    return '#';
  }
  return ' ';
}

int main() {
  std::ifstream input("resources/aoc-input.txt");
  std::string line;
  int cycle = 1;
  int X = 1; // X is the middle of the sprite
  while (std::getline(input, line)) {
    std::string instruction, increment;
    std::istringstream iss(line);
    iss >> instruction >> increment;
    int signal = (increment == "") ? 0 : std::stoi(increment);
    for (int iCycle = 0; iCycle < instructionCycles[instruction]; iCycle++) {
      std::cout << writePixel(X, cycle);
      if (cycle++ % SCREEN_WIDTH == 0) {
        std::cout << std::endl;
      }
    }
    X += signal;
  }

  return 0;
}