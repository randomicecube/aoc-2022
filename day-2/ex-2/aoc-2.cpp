#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define MODULO_NEGATIVE(x, y) ((x % y) + y) % y

enum class plays { ROCK = 1, PAPER = 2, SCISSORS = 3 };
enum class outcomes { LOSE = 0, DRAW = 3, WIN = 6 };

// clang-format off
const std::map<char, plays> opponent = {
  {'A', plays::ROCK},
  {'B', plays::PAPER},
  {'C', plays::SCISSORS}
};

const std::map<char, outcomes> player = {
  {'X', outcomes::LOSE},
  {'Y', outcomes::DRAW},
  {'Z', outcomes::WIN}
};

const std::vector<plays> helper = {
  plays::ROCK, plays::PAPER, plays::SCISSORS,
};

// clang-format on

int main() {
  std::ifstream input{"resources/aoc-2-input.txt"};
  std::string line;
  int score = 0;
  while (std::getline(input, line)) {
    char opponent_play, player_outcome;
    sscanf(line.c_str(), "%c %c", &opponent_play, &player_outcome);
    outcomes goal = player.at(player_outcome);
    plays opponent_choice = opponent.at(opponent_play);
    int index = (int)opponent_choice - 1;
    switch (goal) {
      case outcomes::LOSE:
        score += (int)helper[MODULO_NEGATIVE(index - 1, 3)] + (int)goal;
        break;
      case outcomes::DRAW:
        score += (int)helper[index] + (int)goal;
        break;
      case outcomes::WIN:
        score += (int)helper[MODULO_NEGATIVE(index + 1, 3)] + (int)goal;
    }
  }
  std::cout << "Score: " << score << std::endl;
  return 0;
}