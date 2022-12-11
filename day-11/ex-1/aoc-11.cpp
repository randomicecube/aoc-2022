#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define NUMBERS "0123456789"
#define INSPECTIONS 20

typedef int Item;
struct Monkey {
  std::vector<Item> items;
  std::string op;
  std::string arg;
  int test;
  std::map<bool, int> thrownMonkeys;
  int inspections = 0;
};

// clang-format off
std::map<std::string, std::function<void(std::string arg, Monkey &m)>> inspect = {
  {"*", [](std::string arg, Monkey &m) {
    for (auto &item : m.items) {
      if (arg == "old") {
        item *= item;
      } else {
        item *= std::stoi(arg);
      }
      item /= 3;
    }
  }},
  {"+", [](std::string arg, Monkey &m) {
    for (auto &item : m.items) {
      if (arg == "old") {
        item += item;
      } else {
        item += std::stoi(arg);
      }
      item /= 3;
    }
  }}
};
// clang-format on

// ignore this being a mess
Monkey parseMonkey(std::ifstream &input) {
  Monkey m;
  std::string line;
  int mTrue, mFalse;

  std::getline(input, line);
  line = line.substr(line.find(": ") + 2);
  do {
    m.items.push_back(std::stoi(line.substr(0, line.find(", "))));
    line = line.substr(line.find(", ") + 2);
  } while (line.find(", ") != std::string::npos);
  m.items.push_back(std::stoi(line));

  std::getline(input, line);
  line = line.substr(line.find("old ") + 4);
  m.op = line.substr(0, line.find(" "));
  m.arg = line.substr(line.find(" ") + 1);

  std::getline(input, line);
  sscanf(line.c_str(), "\tTest: divisible by %d", &m.test);

  std::getline(input, line);
  line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
  mTrue = std::stoi(line.substr(line.find_first_of(NUMBERS)));

  std::getline(input, line);
  line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
  mFalse = std::stoi(line.substr(line.find_first_of(NUMBERS)));
  m.thrownMonkeys = {{true, mTrue}, {false, mFalse}};
  return m;
}

void inspectMonkeys(std::vector<Monkey> &monkeys) {
  for (auto &m : monkeys) {
    inspect[m.op](m.arg, m);
    m.inspections += (int)m.items.size();
    for (auto item : m.items) {
      monkeys[m.thrownMonkeys[item % m.test == 0]].items.push_back(item);
    }
    m.items.clear();
  }
}

// clang-format off
int getMonkeyBusiness(std::vector<Monkey> monkeys) {
  std::sort(monkeys.begin(), monkeys.end(), [](const Monkey &a, const Monkey &b) {
    return a.inspections > b.inspections;
  });
  for (auto &m : monkeys) {
    std::cout << "Monkey has " << m.inspections << " inspections" << std::endl;
  }
  return monkeys[0].inspections * monkeys[1].inspections;
}
// clang-format on 

int main() {
  std::ifstream input("resources/aoc-input.txt");
  std::string line;
  std::vector<Monkey> monkeys;
  while (std::getline(input, line)) {
    if (line.find("Monkey") != std::string::npos) {
      monkeys.push_back(parseMonkey(input));
    }
  }

  for (int i = 0; i < INSPECTIONS; i++) {
    std::cout << "Inspection " << i + 1 << std::endl;
    inspectMonkeys(monkeys);
  }
  std::cout << "Monkey business: " << getMonkeyBusiness(monkeys) << std::endl;
  return 0;
}