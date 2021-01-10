//
// Created by knapp on 05/12/2020.
//

#include "playerMain.h"

namespace player {
int move(std::shared_ptr<BoardLogic> board, char colour) {
  int move;
  bool running = true;

  std::cout << "Please make your move";

  while (running) {
    std::cin >> move;

    if (move < 7 && move >= 0) {

      bool result = board->addMove(move, colour);

      if (result == true) {
        return move;
      } else {
        std::cout << "please select a row which is not full";
      }
    } else {
      std::cout << "please make a move in the range 0-5";
    }
  }
}

} // namespace player
