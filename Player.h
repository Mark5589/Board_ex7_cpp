//
// Created by mark  gurin on 17/05/2018.
//
#pragma once

#ifndef BOARD_PLAYER_H
#define BOARD_PLAYER_H

#include <string>
#include "Board.h"
using namespace std;

class Player {
private:
//    char myChar;


public:
    char myChar;
    Player():myChar(){}
    Player(const Player& p): myChar(p.getChar()){}
    Player(const char& c);
    char getChar() const {return myChar; }
    void setChar(char c){myChar = c;}

    virtual const std::string name() const = 0;
    virtual const Coordinate play(const Board& board) = 0;
};


#endif //BOARD_PLAYER_H
