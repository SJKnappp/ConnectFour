//
// Created by knapp on 05/12/2020.
//

#include "playerMain.h"

namespace player {
void spiller(std::shared_ptr<char[6][6]> bræt) {
  int bevægeSig;

  std::cout << "vælg dit bevæge sig";
  std::cin >> bevægeSig;

  bool reslutat = BoardLogic::tilføje(bræt, bevægeSig);
}

} // namespace player
