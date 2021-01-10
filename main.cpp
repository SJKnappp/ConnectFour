#include "main.h"

void gameSetup(std::shared_ptr<char[7][6]> board,
               std::shared_ptr<bool[2]> IsAi) {

  bool validated = false;

  // initiate board values
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 6; j++) {
      board.get()[i][j] = ' ';
    }
  }

  char colour = 'y';
  for (int x = 0; x < 2; x++) {
    bool isAi;
    bool chossen = false;
    std::string choice;
    std::cout << "is " << colour << " an AI y/n";

    while (chossen == false) {
      std::cin >> choice;
      chossen = true;
      if (choice == "y")
        isAi = true;
      else if (choice == "n")
        isAi = false;
      else {
        chossen = false;
        std::cout << "option no recognised is " << colour << " an AI y/n: ";
      }
    }
    colour = 'r';
    IsAi[x] = isAi;
  }
}

int main() {

  srand(time(NULL));

  std::shared_ptr<char[7][6]> board(new char[7][6]);
  std::shared_ptr<bool[2]> IsAi(new bool[2]);

  board[1][1] = ' ';

  gameSetup(board, IsAi);

  char colour = 'y';
  int player = 0;

  bool running = true;
  while (running) {

    BoardLogic::PrintBoard(board);
    int move;
    if (IsAi[player] == false) {
      move = player::move(board, colour);
    } else {
      move = Ai::AiTurn(board, colour, false, 2);
    }
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
