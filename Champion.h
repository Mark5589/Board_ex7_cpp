//
// Created by mark  gurin on 18/05/2018.
//

#ifndef BOARD_CHAMPION_H
#define BOARD_CHAMPION_H

#include "Player.h"

class Champion: public Player {
public:
    const string name() const override { return "Mark Gurin"; }
    const Coordinate play(const Board& board) override;
};


#endif //BOARD_CHAMPION_H
