//
// Created by knapp on 13/12/2020.
//

#ifndef CONNECTFOUR_AI_H
#define CONNECTFOUR_AI_H

#include "../GameLogic/BoardLogic.h"
#include <stdlib.h>
#include <thread>
#include <vector>

namespace Ai {

class Move {
public:
  int move = 7, score = -1000;

  Move(int Move, int Score) {
    move = Move;
    score = Score;
  }
};

std::vector<Move> minMax(BoardLogic::Board board, int targetDepth, char colour,
                         int depth = 0,
                         int friendly = 1); // returns Score
int AiTurn(std::shared_ptr<char[7][6]> board, char colour, bool first,
           int targetDepth); // returns move
                             // namespace Ai
int Score(std::shared_ptr<char[7][6]> board, int colour, int friendly, int move,
          int height = -10, int count = 0, int direction = 0);
}; // namespace Ai

#endif // CONNECTFOUR_AI_H
