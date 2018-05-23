//
// Created by mark  gurin on 18/05/2018.
//

#include "TicTacToe.h"

TicTacToe::TicTacToe(int n): boardG(n) {


}

Board& TicTacToe::board()  {
    return this->boardG;
}

Player& TicTacToe::winner()  const {
    return *this->winnerG;
}

void TicTacToe::play( Player &p1,  Player &p2) {
    board_reset();
    p1.setChar('X');
    p2.setChar('O');
    winnerG = &p2;

    bool gameOn = true;

    while(gameOn){
        gameOn = check_board('X');
        if(!gameOn){
            winnerG = &p1; break;
        }
        gameOn = check_board('O');
        if(!gameOn){
            winnerG = &p2; break;
        }

        //*Algo:
        // Get the p1 move
        // check board,
        // get p2 move ,
        // check board
        // if there was winner in some stage above , update the winner stop the game
        // if there is no winner continue the game.*/
        try {


            Coordinate p1_move = p1.play(boardG);
            if (boardG[p1_move] != '.') { // tries to override other move = auto lose.
                winnerG = &p2;
                break;
            }

            boardG[p1_move] = p1.getChar();
            gameOn = check_board(p1.getChar());
            if (gameOn == false) {
                winnerG = &p1;
                break;
            }
        }
        catch(const std::string& message)
        {
            std::cout << message << std::endl;
            winnerG = &p2;
            break;
        }
        try{
            Coordinate p2_move = p2.play(boardG);
            if (boardG[p2_move] != '.') { // tries to override other move = auto lose.
                winnerG = &p1;
                break;
            }
            boardG[p2_move] = p2.getChar();
            gameOn = check_board(p2.getChar());
            if (gameOn == false) {
                winnerG = &p2;
                break;
            }
        }catch (const std::string& message){
            std::cout << message << std::endl;
            winnerG = &p1;
            break;
        }

//        std::cout << boardG << std::endl;

    }
//    if(winnerG == nullptr){
//        winnerG = &p2;
//    }

}

bool TicTacToe::check_board(char c) {
    uint count =0;
    bool order;
    //find row of c ('X' or 'O')
    for (uint i = 0; i <  boardG.size(); ++i) {
        order = true;
        count = 0;
        for (uint j = 0; j < boardG.size() && order; ++j) {
            Coordinate co{i,j};
            if(boardG[co] == c){
                ++count;
                if(count == boardG.size()) return false;
            }
            else order = false;
        }
        if(count == boardG.size()) return false;
    }
    // find by columns
    for (uint j = 0; j <  boardG.size(); ++j) {
        order = true;
        count = 0;
        for (uint i = 0; i < boardG.size() && order; ++i) {
            Coordinate co{i,j};
            if(boardG[co] == c){
                ++count;
                if(count == boardG.size()) return false;
            }
            else order = false;
        }
        if(count == boardG.size()) return false;
    }

    count = 0;
    order = true;
    for(uint i = 0 ; i< boardG.size() && order ; ++i){
        Coordinate co{i,i};
        if(boardG[co] == c){
            ++count;
            if(count == boardG.size()) return false;
        }
        else order = false;
    }
    if(count == boardG.size()) return false;

    count = 0;
    order = true;

    for(uint i = 0 ; i< boardG.size() ; i++){
        Coordinate co{i ,(uint)boardG.size()-1-i};
        if(boardG[co] == c){
            count++;
            if(count == boardG.size()) return false;
        }
    }
//    std::cout << boardG << std::endl;

//    for(uint i = boardG.size()-1 , j = 0; i > 0 && j<boardG.size() && order ; --i , ++j){
//        Coordinate co{i,j};
//        if(boardG[co] == c){
//            count++;
//            if(count == boardG.size()) return false;
//        }
//        else order = false;
//    }
//    if(count == boardG.size()) return false;

    return true;
}

//TicTacToe::~TicTacToe() {
//    delete boardG;
//
//}


