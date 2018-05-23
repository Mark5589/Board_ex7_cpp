//
// Created by mark  gurin on 17/05/2018.
//

#include "Player.h"

Player::Player(const char &c) {
    if(c == 'X' || c == 'O'){
        myChar = c;
    }
    else
    {
        IllegalCharException e;
        e.setChar(c);
        throw e;
    }

}


