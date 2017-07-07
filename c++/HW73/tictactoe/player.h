#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>
#include <ctime>

double F_is_this_number (const char symbol);

class Player
{
private:
    int numberWins;
    static const int moveNumber = 9;
    int* playerMoves;
public:
    Player();
    virtual ~Player();
    int getPlayerWins() const {return numberWins;}
    void setPlayerWins() {++numberWins;}
    void resetPlayerWins() {numberWins = 0;}
    void resetPlayerMoves();
    void setPlayerMove(int, int);
    void printPlayerMoves() const;
    virtual size_t move() = 0;
};

class Human: public Player
{
private:
public:
    Human() {}
    ~Human() {}
    size_t move();
    void Human1Func();
};

class Bot_L1: public Player
{
private:
public:
    Bot_L1() {}
    ~Bot_L1() {}
    size_t move();
    void Bot1Func();
};





#endif // PLAYER_H
