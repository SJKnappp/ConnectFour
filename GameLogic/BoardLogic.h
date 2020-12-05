//
// Created by knapp on 05/12/2020.
//

#ifndef CONNECTFOUR_BOARDLOGIC_H
#define CONNECTFOUR_BOARDLOGIC_H

#include <iostream>
#include <memory>

namespace BoardLogic {
void PrintBoard(std::shared_ptr<char[6][6]> board);
bool TilladtFlyting(std::shared_ptr<char[6][6]> bræt, int flytte);
bool tilføje(std::shared_ptr<char[6][6]>, int flytte);
}; // namespace BoardLogic

#endif // CONNECTFOUR_BOARDLOGIC_H
