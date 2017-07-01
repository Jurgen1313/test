#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>

void printField(const int* ttt, const size_t lenght, const size_t Col);

int humanNumber(const int* Field);

int robotNumber(const int* Field);

int whoWin (int* Field, const size_t lenght, const size_t Col, size_t& Player1Wins_, size_t& Player2Wins_);

void EmptyField(int* Field, const size_t lenght);

void choosePlayer (int& Player1_, int& Player2_);

#endif // TICTACTOE_H
