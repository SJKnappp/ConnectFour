#include "main.h"
#include <iostream>
#include <memory>

void gameSetup(std::shared_ptr<char[6][6]> board, std::shared_ptr<bool[2]> IsAi){

    bool validated = false;

    // initiate board values
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
          board.get()[i][j] = ' ';
        }
    }

    while(!validated){
        //TODO create player options when AI exists
        validated = true;
    }

}


int main() {

  std::shared_ptr<char[6][6]> Board(new char[6][6]);
  std::shared_ptr<bool[2]> IsAi(new bool[2]);

  Board[1][1] = ' ';

  gameSetup(Board, IsAi);

  bool running = true;
  int i = 0;
  while (running) {
    BoardLogic::PrintBoard(Board);
    player::spiller(Board);
    i += 1;
    std::cout << i;
    running = false;
  }

  std::cout << "Hello, World!" << std::endl;
    return 0;
}
