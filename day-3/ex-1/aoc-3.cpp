#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

inline int get_letter_score(char c) { return c >= 'a' ? c - 'a' + 1 : c - 'A' + 27; }

int main() {
  std::ifstream input{"aoc-3-input.txt"};
  std::string line;
  int score = 0;
  while (getline(input, line)) {
    std::string first = line.substr(0, line.size() / 2);
    std::string second = line.substr(line.size() / 2);
    std::map<char, bool> found;
    std::for_each(first.begin(), first.end(), [&found](char c) { found[c] = true; });
    std::for_each(second.begin(), second.end(), [&found, &score](char c) {
      if (found[c]) {
        score += get_letter_score(c);
        found.erase(c); // avoid double counting
      }
    });
  }
  std::cout << score << std::endl;
  return 0;
}