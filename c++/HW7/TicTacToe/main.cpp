#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tictactoe.h"

using namespace std;

int main()
{
    const size_t n = 3; // Col
    const size_t m = 3; // Row
    size_t Player1Wins = 0;
    size_t Player2Wins = 0;
    int time_val = time(NULL);
    srand(time_val);

    int Player1 = 0; // 0 - BOT
    int Player2 = 0; // 1 - Human
    int PlayerMoves[n*m] = {0};

    // tic tac toe ---> ttt
    // ttt[cellNumber] = 10 ---> O
    // ttt[cellNumber] = 11 ---> X

    const size_t tttLenght = n * m;
    int tttField [tttLenght];// = {1,2,3,4,5,6,7,8,9};

    system("cls");
    cout << "\tWelcome to tic tac toe game\n";
    EmptyField(tttField, tttLenght);
    printField(tttField, tttLenght, n);
    choosePlayer (Player1, Player2);
    printField(tttField, tttLenght, n);
    cout << endl;

    for (;;) // Play
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
//                cellNumber = findBestMove(tttField);
                cellNumber = robotNumber(tttField);
//            Player1Moves[inputCount] = cellNumber + 1;
            PlayerMoves[inputCount] = cellNumber + 1;

//            Player1Moves  += static_cast<char>(cellNumber + '0');
            tttField[cellNumber] = 10;
            Player = 1;
        }
        else    // second player
        {
            cout << "Player 2\n";
            if (Player2 == 1)
                cellNumber = humanNumber(tttField);
            else
//                cellNumber = findBestMove(tttField);
                cellNumber = robotNumber(tttField);
//            Player2Moves[inputCount] = cellNumber + 1;
            PlayerMoves[inputCount] = cellNumber + 1;
            tttField[cellNumber] = 11;
            Player = 0;
        }
        ++inputCount;
        system("cls");
        printField(tttField, tttLenght, n);
        cout << endl;

        int isWinner = whoWin (tttField, tttLenght, n, Player1Wins, Player2Wins);

        if ( inputCount == 9 || isWinner)
        {
            cout << "\nGAME OVER!!!\n";
            if (inputCount == 9)
                cout << "DRAW GAME\n";

            cout << "Player 1 Moves : ";
            for (int i = 0; i < inputCount; i += 2)
                cout << PlayerMoves[i] << " ";
            cout << "\nPlayer 2 Moves : ";
            for (int i = 1; i < inputCount; i += 2)
                cout << PlayerMoves[i] << " ";

            cout << "\n\nPlayer 1 Wins " << Player1Wins << " times\n";
            cout << "Player 2 Wins " << Player2Wins << " times\n";
            EmptyField(tttField,tttLenght);

            cout << "\nWant to play again?\n";
            cout << "type <Y> to continue or <N> to exit : ";
            char again;
            cin >> again;
            if (again == 'Y' || again == 'y')
            {
                system("cls");
                EmptyField(tttField, tttLenght);
                choosePlayer(Player1, Player2);
                printField(tttField, tttLenght, n);
                cout << endl;
                inputCount = 0;
                Player = 0;
            }
            else
                return 0;
        }
    }
}
