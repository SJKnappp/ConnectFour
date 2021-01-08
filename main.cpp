#include "main.h"

void gameSetup(std::shared_ptr<char[6][6]> board,
               std::shared_ptr<bool[2]> IsAi) {

  bool validated = false;

  // initiate board values
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      board.get()[i][j] = ' ';
    }
  }

  while (!validated) {
    // TODO create move options when AI exists
    validated = true;
  }
}

int main() {

  std::shared_ptr<char[6][6]> board(new char[6][6]);
  std::shared_ptr<bool[2]> IsAi(new bool[2]);

  board[1][1] = ' ';

  gameSetup(board, IsAi);

  char colour = 'y';

  bool running = true;
  while (running) {

    BoardLogic::PrintBoard(board);
    int move = player::move(board, colour);

    int checkWin = BoardLogic::checkWin(board, move, -10, colour);
    if (checkWin == 3) {
      BoardLogic::PrintBoard(board);
      std::cout << colour << " has won";
      return 0;
    }
    bool checkEnd = BoardLogic::checkEnd(board);
    if (checkEnd == 1) {
      BoardLogic::PrintBoard(board);
      std::cout << "game is drawn";
      return 0;
    }

    if (colour == 'y')
      colour = 'r';
    else
      colour = 'y';
  }

  std::cout << "Hello, World!" << std::endl;
  return 0;
}
