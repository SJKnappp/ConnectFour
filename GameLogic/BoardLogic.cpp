//
// Created by knapp on 05/12/2020.
//

#include "BoardLogic.h"

print(std::shared_ptr<char[6][6]> board){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}
