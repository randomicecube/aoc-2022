#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

// check if there's any overlap at all
#define OVERLAP(a, b, c, d) (std::max(a, c) <= std::min(b, d))

int main() {
  std::ifstream input{"resources/aoc-4-input.txt"};
  std::string line;
  int score = 0;
  while (getline(input, line)) {
    int first_begin, first_end, second_begin, second_end;
    sscanf(line.c_str(), "%d-%d,%d-%d", &first_begin, &first_end, &second_begin, &second_end);
    if (OVERLAP(first_begin, first_end, second_begin, second_end)) {
      score++;
    }
  }
  std::cout << score << std::endl;
  return 0;
}