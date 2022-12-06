#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <set>

struct State {
  std::vector<char> lastFour;
  std::set<char> sequence;
  int pointer = 0;
};

int main() {
  std::ifstream input("resources/aoc-input.txt");
  struct State state;
  char c;
  while (state.sequence.size() != 4) {
    if (state.lastFour.size() == 4) {
      if (std::find(++state.lastFour.begin(), state.lastFour.end(), state.lastFour[0]) == state.lastFour.end()) {
        state.sequence.erase(state.lastFour[0]);
      }
      state.lastFour.erase(state.lastFour.begin());
    } 
    input.get(c);
    state.lastFour.push_back(c);
    state.sequence.insert(c);
    state.pointer++;
  }
  std::cout << "Pointer: " << state.pointer << std::endl;
  std::cout << std::endl;
  return 0;
}