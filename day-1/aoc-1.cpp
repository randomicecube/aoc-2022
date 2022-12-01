#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::vector<int> calories;
  int currentCalories = 0;
  std::ifstream file;
  file.open("aoc-1-input.txt");
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      if (line != "") {
        currentCalories += std::stoi(line);
        continue;
      }
      calories.push_back(currentCalories);
      currentCalories = 0;
    }
  }
  file.close();
  std::sort(calories.begin(), calories.end());
  std::cout << "Top three: " << std::accumulate(calories.end() - 3, calories.end(), 0) << std::endl;
  return 0;
}