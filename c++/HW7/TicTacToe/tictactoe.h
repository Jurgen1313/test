#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>

void printField(const int* ttt, const size_t lenght, const int Col);

int humanNumber(const int* Field);

int robotNumber(const int* Field);

void whoWin (const int* Field, const size_t lenght, const int Col, size_t& Player1Wins_, size_t& Player2Wins_);

void EmptyField(int* Field, const size_t lenght);

#endif // TICTACTOE_H
