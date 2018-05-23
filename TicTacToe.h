//
// Created by mark  gurin on 18/05/2018.
//

#ifndef BOARD_TICTACTOE_H
#define BOARD_TICTACTOE_H

#include "Board.h"
#include "Player.h"


class TicTacToe {
    Board boardG;
    Player* winnerG;
    bool check_board(char c);
    void board_reset(){boardG = '.'; } // TODO: at the starting of every game , the board should be reset to nil.

public:
    TicTacToe(int n);
//    ~TicTacToe();
    void play( Player& p1,  Player& p2);
     Board& board() ;
     Player& winner() const;


};


#endif //BOARD_TICTACTOE_H
