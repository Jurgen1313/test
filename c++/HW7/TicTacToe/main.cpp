#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printField(const int* ttt, const size_t lenght)
{
    size_t element = 0;
    for (size_t i = 0; i < lenght; ++i)
    {
        cout << "|";//<< ttt[i];
        if (ttt[i] != 10 && ttt[i] != 11)
            cout << ttt[i];
        else if (ttt[i] == 10)
            cout << "O";
        else
            cout << "X";
        ++element;
        if ( element == 3)
        {
            element = 0;
            cout << "|" << endl;
        }

    }
}

int humanNumber(const int* Field)
{
    int cellNumber = 0;
    cout << "Put cell number : ";
    cin >> cellNumber;
    --cellNumber;
    while (Field[cellNumber] == 10 || Field[cellNumber] == 11)
    {
        cout << "Put cell number : ";
        cin >> cellNumber;
        --cellNumber;
    }
    return cellNumber;
}

int robotNumber(const int* Field)
{
    int cellNumber;
    cellNumber = rand() % 8;
    while (Field[cellNumber] == 10 || Field[cellNumber] == 11)
    {
        cellNumber = rand() % 8;
    }
    cout << "random : " << cellNumber + 1 << endl;
    return cellNumber;
}


int main()
{

    int time_val = time(NULL);
    srand(time_val);

    // ttt[cellNumber] = 10 ---> O
    // ttt[cellNumber] = 11 ---> X

    int tttField [] = {1,2,3,4,5,6,7,8,9};
    size_t tttLenght = sizeof(tttField)/sizeof(tttField[0]);
//    //    cout << " -----" << endl;
//        cout << "|O|X|X|" << endl;
//    //    cout << " -----" << endl;
//        cout << "|O|X|X|" << endl;
//    //    cout << " -----" << endl;
//        cout << "|O|X|X|" << endl << endl;
//    //    cout << " -----" << endl;


    printField(tttField, tttLenght);

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

        printField(tttField, tttLenght);
        cout << endl;

        if ( inputCount == 9)
        {
            cout << "GAME OVER!!!";
            cout << "\nDRAW GAME\n";
            return 0;
        }
    }




//    cout << "| | | |" << endl;
//    cout << "| | | |" << endl;
//    return 0;
}
