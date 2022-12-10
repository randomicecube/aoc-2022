#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

std::map<std::string, int> instructionCycles = {{"addx", 2}, {"noop", 1}};

bool inline isRelevantCycle(int cycle) { return cycle % 40 == 20 && cycle <= 220; }

int main() {
  std::ifstream input("resources/aoc-input.txt");
  std::string line;
  int cycle = 1;
  int X = 1;
  int score = 0;
  while (std::getline(input, line)) {
    std::string instruction, increment;
    std::istringstream iss(line);
    iss >> instruction >> increment;
    int signal = (increment == "") ? 0 : std::stoi(increment);
    for (int iCycle = 0; iCycle < instructionCycles[instruction]; iCycle++) {
      if (isRelevantCycle(cycle)) {
        score += X * cycle;
        std::cout << "Cycle " << cycle << " - Score: " << score << std::endl;
      }
      cycle++;
    }
    X += signal;
  }
  std::cout << "Final score: " << score << std::endl;
  return 0;
}