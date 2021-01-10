//
// Created by knapp on 13/12/2020.
//

#include "Ai.h"

namespace Ai {

int AiTurn(std::shared_ptr<char[6][6]> board, char colour, bool first,
           int targetDepth) {
  std::vector<Move> turnCollection;
  Move turn(-1, -1);

  if (first) {
    turn.move = rand() % 6;
  } else {
    turnCollection = minMax(board, targetDepth, colour);
    turn = turnCollection[rand() % turnCollection.size()];
  }
  BoardLogic::addMove(board, turn.move, colour);

  return turn.move;
}

std::vector<Move> minMax(std::shared_ptr<char[6][6]> board, int targetDepth,
                         char colour, int depth, int friendly) {
  std::vector<Move> best;
  best.push_back(Move(-1, -1000));

  for (int i = 0; i < 6; i++) {
    int currentScore = Score(board, colour, friendly, i);
    Move currentMove(i, currentScore);

    if (!BoardLogic::boardSpaceAvailable(board, i)) {
      continue;
    }
    if (depth < targetDepth) {
      std::vector<Move> scoreCollection =
          minMax(board, targetDepth, colour, depth + 1, friendly * -1);
      Move score = scoreCollection[rand() % scoreCollection.size()];

      currentMove.score = score.score;
      if (currentMove.score > best[0].score) {
        best.clear();
        best.push_back(currentMove);
      }
      if (currentMove.score = best[0].score)
        best.push_back(currentMove);
    }
  }
  return best;
}

int Score(std::shared_ptr<char[6][6]> board, int colour, int friendly, int move,
          int height, int count, int direction) {
  bool result = false;
  bool player = colour;
  if (friendly == -1) {
    if (colour == 'y')
      player = 'r';
    if (colour == 'r')
      player = 'y';
  }

  if (height == -10) {
    height = BoardLogic::getHeight(board, move);
  }

  if (move < 0 || move >= 6 || height < 0 || height >= 6) {
    return false;
  }

  if (board[move][height] != player)
    return false;

  int temp;
  int best;
  if (count < 3) {
    if (direction == 0 || direction == 1) {
      temp = Score(board, colour, friendly, move + 1, height, count + 1, 1);
    }
    if (direction == 0 || direction == 5) {
      temp += Score(board, colour, friendly, move - 1, height, count + 1, 5);
      if (temp > best)
        best = temp;
    }
    if (direction == 0 || direction == 2) {
      temp = Score(board, colour, friendly, move + 1, height + 1, count + 1, 2);
    }
    if (direction == 0 || direction == 6) {
      temp +=
          Score(board, colour, friendly, move - 1, height - 1, count + 1, 6);
      if (temp > best)
        best = temp;
    }
    if (direction == 0 || direction == 3) {
      temp = Score(board, colour, friendly, move + 1, height - 1, count + 1, 3);
    }
    if (direction == 0 || direction == 7) {
      temp +=
          Score(board, colour, friendly, move - 1, height + 1, count + 1, 7);
      if (temp > best)
        best = temp;
    }
    if (direction == 0 || direction == 4) {
      temp = Score(board, colour, friendly, move, height + 1, count + 1, 4);
    }
    if (direction == 0 || direction == 8) {
      temp += Score(board, colour, friendly, move, height - 1, count + 1, 8);
      if (temp > best)
        best = temp;
    }
    if (direction != 0)
      best = result;
    if (best < result)
      best = result;

    if (best > count)
      return best;

    return result;
  }
}

} // namespace Ai