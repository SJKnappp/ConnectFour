//
// Created by knapp on 05/12/2020.
//

#include "BoardLogic.h"

BoardLogic::BoardLogic(std::shared_ptr<bool[2]> IsAi) {
  bool validated = false;

  // initiate board values
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 6; j++) {
      board[i][j] = ' ';
    }
  }

  char colour = 'y';
  for (int x = 0; x < 2; x++) {
    bool isAi;
    bool chossen = false;
    std::string choice;
    std::cout << "is " << colour << " an AI y/n";

    while (chossen == false) {
      std::cin >> choice;
      chossen = true;
      if (choice == "y")
        isAi = true;
      else if (choice == "n")
        isAi = false;
      else {
        chossen = false;
        std::cout << "option no recognised is " << colour << " an AI y/n: ";
      }
    }
    colour = 'r';
    IsAi[x] = isAi;
  }
}

void BoardLogic::PrintBoard() {
  std::cout << "0123456" << std::endl;
  for (int j = 5; j >= 0; j--) {
    for (int i = 0; i < 7; i++) {
      std::cout << board[i][j];
    }
    std::cout << std::endl;
  }
}

bool BoardLogic::boardSpaceAvailable(int move) {
  if (board[move][5] == ' ')
    return true;
  return false;
}

bool BoardLogic::addMove(int move, char player) {
  if (this->boardSpaceAvailable(move) == true) {
    for (int i = 0; i < 6; i++) {
      if (board[move][i] == ' ') {
        board[move][i] = player;
        return true;
      }
    }
  } else
    return false;
}

bool BoardLogic::checkEnd() {
  for (int i = 0; i < 6; i++) {
    if (board[i][5] == ' ') {
      return false;
    }
  }
  return true;
}

int BoardLogic::getHeight(int move) {
  for (int i = 5; i > 0; i--) {
    if (board[move][i] != ' ') {
      return i;
    }
  }
}

// dir 0 still 1 - 8 clockwise
int BoardLogic::checkWin(int move, int height, char player, int count,
                         int direction) {
  int result = 0;
  int best = 0;
  if (height == -10) {
    height = getHeight(move);
  }

  if (move < 0 || move >= 7 || height < 0 || height >= 6) {
    return 0;
  }

  if (board[move][height] != player)
    return 0;

  if (count < 3) {
    if (direction == 0 || direction == 1) {
      result = checkWin(move + 1, height, player, count + 1, 1);
    }
    if (direction == 0 || direction == 5) {
      result += checkWin(move - 1, height, player, count + 1, 5);
      if (best < result)
        best = result;
    }
    if (direction == 0 || direction == 2) {
      result = checkWin(move + 1, height + 1, player, count + 1, 2);
    }
    if (direction == 0 || direction == 6) {
      result += checkWin(move - 1, height - 1, player, count + 1, 6);
      if (best < result)
        best = result;
    }
    if (direction == 0 || direction == 3) {
      result = checkWin(move, height + 1, player, count + 1, 3);
    }
    if (direction == 0 || direction == 7) {
      result += checkWin(move, height - 1, player, count + 1, 7);
      if (best < result)
        best = result;
    }
    if (direction == 0 || direction == 4) {
      result = checkWin(move - 1, height + 1, player, count + 1, 4);
    }
    if (direction == 0 || direction == 8) {
      result += checkWin(move + 1, height - 1, player, count + 1, 8);
      if (best < result)
        best = result;
    }
    if (direction != 0)
      best = result;
    if (best < result)
      best = result;

    if (best > count)
      return best;
    return count;
  }
  return count;
}

bool BoardLogic::checkMoveMade(BoardLogic old) {
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 6; j++) {
      if (this->board[i][j] != old.board[i][j]) {
        return true;
      }
    }
  }
  return false;
}