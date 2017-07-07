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
public:
    Player(size_t wins = 0):numberWins(wins) {}
    int getPlayerWins() const {return numberWins;}
    void setPlayerWins() {++numberWins;}
    void resetPlayerWins() {numberWins = 0;}
    virtual size_t move() = 0;
};

class Human: public Player
{
public:
    Human() {}
    size_t move();
    void printWin() const { std::cout << getPlayerWins();}
    void win () {setPlayerWins();}
    void restWins () {resetPlayerWins();}
};

class Bot_L1: public Player
{
public:
    Bot_L1() {}
    size_t move();
    void printWin() const { std::cout << getPlayerWins();}
    void win () {setPlayerWins();}
    void restWins () {resetPlayerWins();}
};





#endif // PLAYER_H
