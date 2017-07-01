#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tictactoe.h"

using namespace std;

int main()
{
    const int n = 3; // Col
    const int m = 3; // Row
    int time_val = time(NULL);
    srand(time_val);

    // ttt[cellNumber] = 10 ---> O
    // ttt[cellNumber] = 11 ---> X

    const size_t tttLenght = n * m;
    int tttField [tttLenght];// = {1,2,3,4,5,6,7,8,9};

    EmptyField(tttField, tttLenght);
    printField(tttField, tttLenght, n);

    for (;;)
    {
        static int inputCount = 0;
        static int Player = 0;
        int cellNumber = 0;

        if (Player == 0)
        {
            cellNumber = humanNumber(tttField);
            tttField[cellNumber] = 10;
            Player = 1;
        }
        else
        {
            cellNumber = robotNumber(tttField);
            tttField[cellNumber] = 11;
            Player = 0;
        }
        ++inputCount;
        system("cls");
        printField(tttField, tttLenght, n);
        cout << endl;

        whoWin (tttField, tttLenght, n);

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
