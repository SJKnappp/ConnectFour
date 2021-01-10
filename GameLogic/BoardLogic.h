//
// Created by knapp on 05/12/2020.
//

#ifndef CONNECTFOUR_BOARDLOGIC_H
#define CONNECTFOUR_BOARDLOGIC_H

#include <iostream>
#include <memory>

namespace BoardLogic {
void PrintBoard(std::shared_ptr<char[7][6]> board);
bool boardSpaceAvailable(std::shared_ptr<char[7][6]> board, int move);
bool addMove(std::shared_ptr<char[7][6]>, int move, char player);
bool checkEnd(std::shared_ptr<char[7][6]> board);
int checkWin(std::shared_ptr<char[7][6]> board, int move, int height,
             char player, int count = 0, int direction = 0);
int getHeight(std::shared_ptr<char[7][6]> board, int move);
}; // namespace BoardLogic

#endif // CONNECTFOUR_BOARDLOGIC_H
