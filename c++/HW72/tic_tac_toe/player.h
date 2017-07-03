#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>
#include <ctime>


class Player
{
    private:
        int Row;
        int Col;
        size_t fieldLenght;
        int PlayerNumber; // 0 - BOT
                          // 1 - Human
        size_t PlayerWin;
        int *Field;

        static size_t CountPlayer;
        size_t Number;
        int* playerMoves;
        static size_t countMoves;

        bool isMove();
        bool Win();
        double F_is_this_number (const char symbol);
        void deleteMoves();

    public:

        Player();

        Player (int PlayerNumber_, int* Field_, size_t PlayerWin_ = 0):
            Row(3), Col(3), fieldLenght(Row * Col), PlayerNumber(PlayerNumber_), PlayerWin(PlayerWin_), Field(Field_)
        {
            ++CountPlayer;
            Number = CountPlayer;
            playerMoves = new int[fieldLenght] {0};
//            if (CountPlayer == 3)
        }

        ~Player()
        {
           --CountPlayer;
            delete[] playerMoves;
        }

        int getWhosPlayer() const
        {
            return PlayerNumber;
        }
        size_t getPlayerWins() const
        {
            return PlayerWin;
        }
        size_t getNumber() const
        {
            return Number;
        }
        void ResetCountMoves();
        void printPlayerMoves() const;

        bool HumanMove();
        bool BotMove();
        bool Move();
};

void EmptyField(int* Field, const size_t lenght);
void printField(const int* Field, const size_t lenght , const size_t Col);
bool F_repeat ();




#endif // PLAYER_H
