#include <fstream>
#include <iostream>
#include <map>
#include <string>

#define MODULO_NEGATIVE(x, y) ((x % y) + y) % y

enum class plays { ROCK = 1, PAPER = 2, SCISSORS = 3 };
enum class outcomes { LOSE = 0, DRAW = 3, WIN = 6 };

// clang-format off
const std::map<char, plays> opponent = {
  {'A', plays::ROCK},
  {'B', plays::PAPER},
  {'C', plays::SCISSORS}
};

const std::map<char, plays> player = {
  {'X', plays::ROCK},
  {'Y', plays::PAPER},
  {'Z', plays::SCISSORS}
};

// the outcome of the game can be calculated by subtracting the player's
// play from the opponent's play. If the result is 0, it's a draw, if it's
// 1 or -2, the player wins, and if it's -1 or 2, the player loses.
const std::map<int, outcomes> outcome = {
  {0, outcomes::DRAW},
  {1, outcomes::WIN},
  {2, outcomes::LOSE},
};
// clang-format on

int main() {
  std::ifstream input{"resources/aoc-2-input.txt"};
  std::string line;
  int score = 0;
  while (std::getline(input, line)) {
    char opponent_play, player_play;
    sscanf(line.c_str(), "%c %c", &opponent_play, &player_play);
    int game_outcome = (int)(player.at(player_play)) - (int)(opponent.at(opponent_play));
    score += (int)(outcome.at(MODULO_NEGATIVE(game_outcome, 3))) + (int)(player.at(player_play));
  }
  std::cout << "Score: " << score << std::endl;
  return 0;
}