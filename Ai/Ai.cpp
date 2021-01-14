//
// Created by knapp on 13/12/2020.
//

#include "Ai.h"

namespace Ai {
// class holder{
// public:
//  std::map<std::array<char, 42>, int> oldMoves;
//};
class minMaxReturn {
public:
  std::vector<Move> move;
  std::map<std::array<char, 42>, int> map;
};

int AiTurn(std::shared_ptr<BoardLogic> board, char colour, bool first,
           int targetDepth) {

  std::map<std::array<char, 42>, int> oldMoves;
  Move turnCollection(oldMoves);
  Move::MoveInfo turn(-1, -1000);

  // std::unique_ptr<holder> hold;
  // hold->oldMoves[board->board] = 1;
  oldMoves.insert(std::pair<std::array<char, 42>, int>(board->board, 0));
  int test = oldMoves.at(board->board);

  turnCollection = minMax(*board, targetDepth, colour, oldMoves);

  if (turnCollection.move.size() == 0) {
    std::cout << "no move";
  }

  turn = turnCollection.move[rand() % turnCollection.move.size()];
  if (turn.move == -1) {
    std::cout << "no move";
  }

  board->addMove(turn.move, colour);

  return turn.move;
}

Move minMax(BoardLogic board, int targetDepth, char colour,
            std::map<std::array<char, 42>, int> oldChecks, int depth,
            int friendly) {
  Move best(oldChecks);

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

    if (oldChecks.contains(tempBoard.board)) {
      Move::MoveInfo possibleBest(i, best.map[board.board]);
      best.FindMove(possibleBest);
      continue;
    }

    int currentScore = friendly * Score(tempBoard, player, friendly, i);
    Move::MoveInfo currentMove(i, currentScore);
    if (depth == targetDepth) {
      best.map[board.board] = currentScore;
    }

    if (currentScore >= 3 || currentScore <= -3) {
      best.move.clear();
      currentMove.score += 197 * friendly;
      best.move.push_back(currentMove);
      best.map[board.board] = currentMove.score;
      return best;
    }

    if (depth < targetDepth) {

      Move scoreCollection = minMax(tempBoard, targetDepth, colour, best.map,
                                    depth + 1, friendly * -1);
      best.map = scoreCollection.map;
      Move::MoveInfo score = scoreCollection.move[0];

      currentMove.score += score.score;

      best.map[tempBoard.board] = currentMove.score;

      best.FindMove(currentMove);
    } else {
      if (best.move[0].score < currentScore) {
        best.move[0].score = currentScore;
        best.move[0].move = i;
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

  if (board.board[move * 6 + height] != player)
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