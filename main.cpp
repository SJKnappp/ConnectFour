#include "main.h"

int main() {

  srand(time(NULL));

  std::shared_ptr<bool[2]> IsAi(new bool[2]);
  std::shared_ptr<BoardLogic> board(new BoardLogic(IsAi));

  char colour = 'y';
  int player = 0;

  bool running = true;

  std::cout << colour << " please select first move";
  std::cout << "0123456";

  while (running) {

    int move;
    BoardLogic old = *board;
    if (IsAi[player] == false) {
      move = player::move(std::shared_ptr<BoardLogic>(board), colour);
    } else {
      move = Ai::AiTurn(board, colour, false, 8);
    }
    board->PrintBoard();

    // bool moveMade = board->checkMoveMade(old);
    if (move == -1) {
      std::cout << "error: no move made";
      return 1;
    }
    int checkWin = board->checkWin(move, -10, colour);
    if (checkWin >= 3) {
      board->PrintBoard();
      std::cout << colour << " has won";
      return 0;
    }
    bool checkEnd = board->checkEnd();
    if (checkEnd == 1) {
      board->PrintBoard();
      std::cout << "game is drawn";
      return 0;
    }

    if (colour == 'y') {
      colour = 'r';
      player = 1;
    } else {
      colour = 'y';
      player = 0;
    }
  }

  std::cout << "Hello, World!" << std::endl;
  return 0;
}
