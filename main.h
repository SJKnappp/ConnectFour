//
// Created by knapp on 05/12/2020.
//

#ifndef CONNECTFOUR_MAIN_H
#define CONNECTFOUR_MAIN_H

#include <iostream>
#include <memory>

#include "Ai/Ai.h"
#include "GameLogic/BoardLogic.h"
#include "player/playerMain.h"

int main();
bool gameSetup(std::shared_ptr<char[6][6]> board,
               std::shared_ptr<bool[2]> IsAi);

#endif // CONNECTFOUR_MAIN_H
