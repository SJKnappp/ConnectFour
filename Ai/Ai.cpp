//
// Created by knapp on 13/12/2020.
//

#include "Ai.h"

namespace Ai {

int AiTurn(std::shared_ptr<BoardLogic> board, char colour, bool first,
           int targetDepth) {
  std::vector<Move> turnCollection;
  Move turn(-1, -1);

  if (first) {
    turn.move = rand() % 6;
  } else {
    turnCollection = minMax(*board, targetDepth, colour);

    if (turnCollection.size() == 0) {
      std::cout << "no move";
    }

    turn = turnCollection[rand() % turnCollection.size()];
    if (turn.move == -1) {
      std::cout << "no move";
    }
  }

  board->addMove(turn.move, colour);

  return turn.move;
}

std::vector<Move> minMax(BoardLogic board, int targetDepth, char colour,
                         int depth, int friendly) {
  std::vector<Move> best;
  best.push_back(Move(-1, -1000));

  char player;
  if (friendly == 1) {
    player = colour;
  } else {
    if (colour == 'y')
      player = 'r';
    else
      player = 'y';
  }

  for (int i = 0; i < 7; i++) {

    if (!board.boardSpaceAvailable(i)) {
      continue;
    }
    BoardLogic tempBoard = board;
    tempBoard.addMove(i, player);

    int currentScore = friendly * Score(tempBoard, player, friendly, i);
    Move currentMove(i, currentScore);

    if (currentScore >= 3 || currentScore <= -3) {
      best.clear();
      currentMove.score += 197 * friendly;
      best.push_back(currentMove);
      return best;
    }

    if (depth < targetDepth) {

      std::vector<Move> scoreCollection =
          minMax(tempBoard, targetDepth, colour, depth + 1, friendly * -1);
      Move score = scoreCollection[rand() % scoreCollection.size()];

      currentMove.score += score.score;
      if (currentMove.score > best[0].score) {
        best.clear();
        best.push_back(currentMove);
      } else if (currentMove.score == best[0].score)
        best.push_back(currentMove);
    } else {
      if (best[0].score < currentScore) {
        best[0].score = currentScore;
        best[0].move = i;
      }
    }
  }
  return best;
}

int Score(BoardLogic board, int colour, int friendly, int move, int height,
          int count, int direction) {
  char player = colour;

  if (height == -10) {
    height = board.getHeight(move);
  }

  if (move < 0 || move >= 7 || height < 0 || height >= 6) {
    return 0;
  }

  if (board.board.at(move * 6 + height) != player)
    return count - 1;

  int temp = 0;
  int best = 0;
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
      best = temp;
    // if (best < result)
    //  best = result;

    if (best > count)
      return best;

    return count;
  }
}

} // namespace Ai