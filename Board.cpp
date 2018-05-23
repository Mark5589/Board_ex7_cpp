//
// Created by mark  gurin on 04/05/2018.
//

#include "Board.h"


Board::Board(int n) {
    this->size_ = n;
//    board = new char*[size()];
    board = new Cell*[size()];
    int i,j;
    for ( i = 0; i < size(); ++i) {
        this->board[i] = new Cell[size()];
    }
    for (i = 0; i < size(); ++i) {
        for (j = 0; j <size() ; j++) {
            this->board[i][j].setCell('.');
        }
    }
}

Board::~Board() {
    for (int i = 0; i < size(); ++i) {
        delete[] board[i];
    }
    delete[] board;

}

std::ostream &operator<<(std::ostream &stream, const Board &other) {
    for (int i = 0; i < other.size(); ++i) {
        for (int j = 0; j < other.size(); ++j) {
            stream << other.board[i][j].getCell();
        }
        stream<<"\n";
    }
    return stream;
}




Cell& Board::operator[](std::initializer_list<uint> list) {
    int row = *list.begin();
    int col = *(list.begin()+1);
    setX(row);
    setY(col);
    if(row >= (*this).size() || row < 0 || col >= (*this).size() || col < 0){
        IllegalCoordinateException ex;
        ex.set(row, col);
        throw ex;
    }


    return this->board[row][col];
}

Cell &Board::operator[](const Coordinate& c) const{
    int row = c.x;
    int col = c.y;
//    setX(row);
//    setY(col);
    if(row >= (*this).size() || row < 0 || col >= (*this).size() || col < 0){
        IllegalCoordinateException ex;
        ex.set(row, col);
        throw ex;
    }


    return this->board[row][col];
}



Board &Board::operator=(char c) {
    if(c == 'X' || c == 'O'){
        int i,j;
        for (i = 0; i < size(); ++i) {
            for (j = 0; j <size() ; j++) {
                board[i][j] = c;
            }
        }
        return *this;
    }
    else if( c == '.'){
        int i, j;
        for (i = 0; i < size(); ++i) {
            for (j = 0; j <size() ; j++) {
                board[i][j] = '.';
            }
        }
        return *this;
    }


    else{
        IllegalCharException ex;
        ex.setChar(c);
        throw ex;
    }
}

Board &Board::operator=(const Board &other) {
    if((*this).board == other.board)return (*this);

        if((*this).size() != other.size()){
            for (int i = 0; i <this->size() ; ++i) {
                delete[] this->board[i];
            }
            delete[] this->board;

            this->size_= other.size();
            this->board = new Cell*[this->size()];
            for (int j = 0; j < size() ; ++j) {
                this->board[j] = new Cell[size()];
            }

            for (int k = 0; k < (*this).size(); ++k) {
                for (int i = 0; i < (*this).size(); ++i) {
                    this->board[k][i] =other.board[k][i];
                }
            }
        }
    return (*this);


}








