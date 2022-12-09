#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define SIGN(x) ((x > 0) - (x < 0))
#define ROPE_LENGTH 10

typedef std::pair<int, int> Coord;
typedef std::set<Coord> Map;
typedef std::vector<Coord> Rope;

std::map<char, Coord> directions = {{'R', {1, 0}}, {'L', {-1, 0}}, {'U', {0, 1}}, {'D', {0, -1}}};

inline void moveCoord(Coord &coord, const Coord &direction) {
  coord.first += direction.first;
  coord.second += direction.second;
}

inline bool isAdjacent(const Coord &coord1, const Coord &coord2) {
  return std::abs(coord1.first - coord2.first) <= 1 && std::abs(coord1.second - coord2.second) <= 1;
}

int main() {
  std::ifstream input("resources/aoc-input.txt");
  std::string line;
  Rope rope(ROPE_LENGTH, {0, 0});
  Map visited = {{0, 0}}; // Tail related
  char direction;
  int distance;
  while (std::getline(input, line)) {
    sscanf(line.c_str(), "%c %d", &direction, &distance);
    // we basically apply the same logic as in day-9/ex-1/aoc-9.cpp to all the ropes' knots
    while (distance-- > 0) {
      // first, we move the head of the rope
      moveCoord(rope.front(), directions[direction]);
      for (int i = 1; i < ROPE_LENGTH; i++) {
        // then, we consider every knot of the rope, and move it towards the head
        if (!isAdjacent(rope[i], rope[i - 1])) {
          rope[i].first += SIGN(rope[i - 1].first - rope[i].first);
          rope[i].second += SIGN(rope[i - 1].second - rope[i].second);
        }
      }
      visited.insert(rope.back());
    }
  }
  std::cout << "The tail visited " << visited.size() << " unique coordinates." << std::endl;
  return 0;
}