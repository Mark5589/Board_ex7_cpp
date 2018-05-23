//
// Created by mark  gurin on 18/05/2018.
//

#include "Champion.h"

const Coordinate Champion::play(const Board &board) {
    if(board[Coordinate{(uint)board.size()-1, 0}] == '.') return {(uint)board.size()-1 , 0 };
    if(board[Coordinate{0, (uint)board.size()-1}] == '.') return {0, (uint)board.size()-1};

    for (uint i = board.size()-2 , j = 1; i > 0 && j<board.size() ; --i , ++j) {
        if(board[Coordinate{i, j}] == '.') return {i, j};
    }
    return {0,0};
}

