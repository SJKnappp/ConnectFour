//
// Created by knapp on 05/12/2020.
//

#ifndef CONNECTFOUR_PLAYERMAIN_H
#define CONNECTFOUR_PLAYERMAIN_H

#include "../GameLogic/BoardLogic.h"
#include <iostream>
#include <memory>
namespace player {
int move(std::shared_ptr<char[6][6]> board, char colour);
};

#endif // CONNECTFOUR_PLAYERMAIN_H
