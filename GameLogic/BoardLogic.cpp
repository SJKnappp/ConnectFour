//
// Created by knapp on 05/12/2020.
//

#include "BoardLogic.h"

namespace BoardLogic {

void PrintBoard(std::shared_ptr<char[6][6]> board) {
  std::cout << "012345" << std::endl;
  for (int j = 5; j >= 0; j--) {
    for (int i = 0; i < 6; i++) {
      std::cout << board[i][j];
    }
    std::cout << std::endl;
  }
}

bool boardSpaceAvailable(std::shared_ptr<char[6][6]> board, int move) {
  if (board[move][5] == ' ')
    return true;
  return false;
}

bool addMove(std::shared_ptr<char[6][6]> board, int move, char player) {
  if (boardSpaceAvailable(board, move) == true) {
    for (int i = 0; i < 6; i++) {
      if (board[move][i] == ' ') {
        board[move][i] = player;
        return true;
      }
    }
  } else
    return false;
}

bool checkEnd(std::shared_ptr<char[6][6]> board) {
  for (int i = 0; i < 6; i++) {
    if (board[i][5] == ' ') {
      return false;
    }
  }
  return true;
}

int getHeight(std::shared_ptr<char[6][6]> board, int move) {
  for (int i = 5; i > 0; i--) {
    if (board[move][i] != ' ') {
      return i;
    }
  }
}

// dir 0 still 1 - 8 clockwise
bool checkWin(std::shared_ptr<char[6][6]> board, int move, int height,
              char player, int count, int direction) {
  bool result = false;
  if (height == -10) {
    height = getHeight(board, move);
  }

  if (move < 0 || move >= 6 || height < 0 || height >= 6) {
    return false;
  }

  if (board[move][height] != player)
    return false;

  if (count < 3) {
    if (direction == 0 || direction == 1) {
      result =
          result || checkWin(board, move + 1, height, player, count + 1, 1);
    }
    if (direction == 0 || direction == 2) {
      result =
          result || checkWin(board, move + 1, height + 1, player, count + 1, 2);
    }
    if (direction == 0 || direction == 3) {
      result =
          result || checkWin(board, move, height + 1, player, count + 1, 3);
    }
    if (direction == 0 || direction == 4) {
      result =
          result || checkWin(board, move - 1, height + 1, player, count + 1, 4);
    }
    if (direction == 0 || direction == 5) {
      result =
          result || checkWin(board, move - 1, height, player, count + 1, 5);
    }
    if (direction == 0 || direction == 6) {
      result =
          result || checkWin(board, move - 1, height - 1, player, count + 1, 6);
    }
    if (direction == 0 || direction == 7) {
      result =
          result || checkWin(board, move, height - 1, player, count + 1, 7);
    }
    if (direction == 0 || direction == 8) {
      result =
          result || checkWin(board, move + 1, height - 1, player, count + 1, 8);
    }

    return result;
  }
  return true;
}

} // namespace BoardLogic
