//
// Created by knapp on 05/12/2020.
//

#ifndef CONNECTFOUR_BOARDLOGIC_H
#define CONNECTFOUR_BOARDLOGIC_H

#include <iostream>
#include <memory>

class BoardLogic {
public:
  std::string board;

  BoardLogic(std::shared_ptr<bool[2]> IsAi);
  void PrintBoard();
  bool boardSpaceAvailable(int move);
  bool addMove(int move, char player);
  bool checkEnd();
  int checkWin(int move, int height, char player, int count = 0,
               int direction = 0);
  int getHeight(int move);
  bool checkMoveMade(BoardLogic old);
}; // namespace BoardLogic

#endif // CONNECTFOUR_BOARDLOGIC_H
