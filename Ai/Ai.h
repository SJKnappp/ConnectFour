//
// Created by knapp on 13/12/2020.
//

#ifndef CONNECTFOUR_AI_H
#define CONNECTFOUR_AI_H

#include "../GameLogic/BoardLogic.h"
#include <map>
#include <stdlib.h>
#include <thread>
#include <vector>

namespace Ai {

class Move {
public:
  class MoveInfo {
  public:
    int move = -1, score = -1000;
    MoveInfo(int _move, int _score) {
      move = _move;
      score = _score;
    }
  };
  std::map<std::array<char, 42>, int> map;
  std::vector<MoveInfo> move;
  Move(std::map<std::array<char, 42>, int> Map) {
    map = Map;
    move.push_back(MoveInfo(-1, -1000));
  }

  void FindMove(MoveInfo compare) {
    if (this->move[0].score < compare.score) {
      this->move.clear();
      this->move.push_back(compare);
    } else if (this->move[0].score == compare.score) {
      this->move.push_back(compare);
    }
  }
};

Move minMax(BoardLogic board, int targetDepth, char colour,
            std::map<std::array<char, 42>, int> oldChecks, int depth = 0,
            int friendly = 1); // returns Score
int AiTurn(std::shared_ptr<BoardLogic> board, char colour, bool first,
           int targetDepth); // returns move
                             // namespace Ai
int Score(BoardLogic board, int colour, int friendly, int move,
          int height = -10, int count = 0, int direction = 0);
}; // namespace Ai

#endif // CONNECTFOUR_AI_H
