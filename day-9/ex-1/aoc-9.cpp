#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>

#define SIGN(x) ((x > 0) - (x < 0))

typedef std::pair<int, int> Coord;
typedef std::set<Coord> Map;

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
  Coord head = {0, 0};
  Coord tail = {0, 0};
  Map visited = {head};
  char direction;
  int distance;
  while (std::getline(input, line)) {
    sscanf(line.c_str(), "%c %d", &direction, &distance);
    while (distance-- > 0) {
      moveCoord(head, directions[direction]);
      if (!isAdjacent(head, tail)) {
        tail.first += SIGN(head.first - tail.first);
        tail.second += SIGN(head.second - tail.second);
      }
      visited.insert(tail);
    }
  }
  std::cout << "The tail visited " << visited.size() << " unique coordinates." << std::endl;
  return 0;
}