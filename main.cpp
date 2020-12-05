#include <iostream>
#include <memory>

void gameSetup(std::shared_ptr<char[6][6]> board, std::shared_ptr<bool[2]> IsAi){

    bool validated = false;

    //intiate baord values
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            board[i][j] = ' ';
        }
    }

    while(!validated){
        //TODO create player options when AI exists
    }

}


int main() {

    std::shared_ptr<char[6][6]> Board = NULL;
    std::shared_ptr<bool[2]> IsAi = NULL;
    gameSetup(Board, IsAi);

    bool running = true;
    int i = 0;
    while(running){
        i += 1;
        std::cout << i;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
