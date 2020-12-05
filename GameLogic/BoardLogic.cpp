//
// Created by knapp on 05/12/2020.
//

#include "BoardLogic.h"

namespace BoardLogic {

void PrintBoard(std::shared_ptr<char[6][6]> board) {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      std::cout << "test" << board[i][j];
    }
    std::cout << std::endl;
  }
}

bool TilladtFlyting(std::shared_ptr<char[6][6]> bræt, int flytte) {
  if (bræt[flytte][5] == ' ')
    return true;
  return false;
}

bool tilføje(std::shared_ptr<char[6][6]> bræt, int flytte, char spiller) {
  if (TilladtFlyting(bræt, flytte) == true) {
    for (int i = 0; i < 6; i++) {
      if (bræt[flytte][i] == ' ') {
        bræt[flytte][i] = spiller;
        return true;
      }
    }
  } else
    return false;
}
} // namespace BoardLogic
