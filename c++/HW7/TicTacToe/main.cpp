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
int main()
{

    int time_val = time(NULL);
    srand(time_val);

    // ttt[cellNumber] = 10 ---> O
    // ttt[cellNumber] = 11 ---> X

    int ttt [] = {1,2,3,4,5,6,7,8,9};
    size_t tttLenght = sizeof(ttt)/sizeof(ttt[0]);
//    //    cout << " -----" << endl;
//        cout << "|O|X|X|" << endl;
//    //    cout << " -----" << endl;
//        cout << "|O|X|X|" << endl;
//    //    cout << " -----" << endl;
//        cout << "|O|X|X|" << endl << endl;
//    //    cout << " -----" << endl;


    printField(ttt, tttLenght);

    for (;;)
    {
        static int inputCount = 0;
        int cellNumber = 0;

        if ( inputCount == 9)
            return 0;

        cout << "Put cell number : ";
        cin >> cellNumber;
        if (ttt[cellNumber] != 10 && ttt[cellNumber] != 11)
        {
            ttt[cellNumber] = 10;
            ++inputCount;
        }
        printField(ttt, tttLenght);
        cout << endl;

//        int rand_number;
//        rand_number = rand() % 9 + 1;
        cellNumber = rand() % 9;
        while (ttt[cellNumber] == 10 || ttt[cellNumber] == 11)
            cellNumber = rand() % 9;

            ttt[cellNumber] = 11;
            ++inputCount;

        printField(ttt, tttLenght);

    }




//    cout << "| | | |" << endl;
//    cout << "| | | |" << endl;
    return 0;
}
