#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tictactoe.h"

using namespace std;

int main()
{
    const size_t n = 3; // Col
    const size_t m = 3; // Row
    size_t Palyer1Wins = 0;
    size_t Palyer2Wins = 0;
    int time_val = time(NULL);
    srand(time_val);

    int Player1 = 0; // 0 - BOT
    int Player2 = 0; // 1 - Human
    char userChoise;

    // tic tac toe ---> ttt
    // ttt[cellNumber] = 10 ---> O
    // ttt[cellNumber] = 11 ---> X

    const size_t tttLenght = n * m;
    int tttField [tttLenght];// = {1,2,3,4,5,6,7,8,9};

    system("cls");
    cout << "\tWelcome to tic tac toe game\n";
    EmptyField(tttField, tttLenght);
    printField(tttField, tttLenght, n);
    cout << "Now it's time to choose PLAYER 1 :\n";
    cout << "type <H> - human or <B> - bot\n";
    cout << "Make your choise! :";
    cin >> userChoise;
    switch (userChoise)
    {
        case 'h':
        case 'H':
        {
            Player1 = 1;
            break;
        }
        case 'b':
        case 'B':
        {
            Player1 = 0;
            break;
        }
    }
    cout << "Now it's time to choose PLAYER 2 :\n";
    cout << "type <H> - human or <B> - bot\n";
    cout << "Make your choise! :";
    cin >> userChoise;
    switch (userChoise)
    {
        case 'h':
        case 'H':
        {
            Player2 = 1;
            break;
        }
        case 'b':
        case 'B':
        {
            Player2 = 0;
            break;
        }
    }

    system("cls");
    printField(tttField, tttLenght, n);
    cout << endl;

    for (;;)
    {
        static int inputCount = 0;
        static int Player = 0;
        int cellNumber = 0;

        if (Player == 0) // first player
        {
            cout << "Player 1\n";
            if (Player1 == 1)
                cellNumber = humanNumber(tttField);
            else
                cellNumber = robotNumber(tttField);
            tttField[cellNumber] = 10;
            Player = 1;
        }
        else    // second player
        {
            cout << "Player 2\n";
            if (Player2 == 1)
                cellNumber = humanNumber(tttField);
            else
                cellNumber = robotNumber(tttField);
//            cellNumber = robotNumber(tttField);
            tttField[cellNumber] = 11;
            Player = 0;
        }
        ++inputCount;
        system("cls");
        printField(tttField, tttLenght, n);
        cout << endl;

        whoWin (tttField, tttLenght, n, Palyer1Wins, Palyer2Wins);

        if ( inputCount == 9)
        {
            cout << "GAME OVER!!!";
            return 0;
        }
    }




//    cout << "| | | |" << endl;
//    cout << "| | | |" << endl;
//    return 0;
}
