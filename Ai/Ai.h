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
  int move, score;

  Move() {
    move = 7;
    score = -1000000;
  }
};

std::vector<Move> minMax(std::shared_ptr<char[6][6]> board, int targetDepth,
                         int depth = 0,
                         int friendly = 1); // returns score
int AiTurn(std::shared_ptr<char[6][6]> board, char colour, bool first,
           int targetDepth); // returns move
};                           // namespace Ai

#endif // CONNECTFOUR_AI_H
