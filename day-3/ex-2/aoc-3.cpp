#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

inline int get_letter_score(char c) { return c >= 'a' ? c - 'a' + 1 : c - 'A' + 27; }

int main() {
  std::ifstream input{"resources/aoc-input.txt"};
  // we'll be working with groups of 3 lines
  std::string line1, line2, line3;
  int score = 0;
  while (getline(input, line1)) {
    getline(input, line2);
    getline(input, line3);
    std::map<char, bool> first, second;
    std::for_each(line1.begin(), line1.end(), [&first](char c) { first[c] = true; });
    std::for_each(line2.begin(), line2.end(), [&first, &second](char c) {
      if (first[c]) {
        second[c] = true;
      }
    });
    std::for_each(line3.begin(), line3.end(), [&second, &score](char c) {
      if (second[c]) {
        score += get_letter_score(c);
        second.erase(c); // avoid double counting
      }
    });
  }
  std::cout << score << std::endl;
  return 0;
}