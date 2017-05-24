#include <QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
//    QCoreApplication a(argc, argv);

    int time_val = time(0);
    int players_number = 1;
    int dices_number = 1;
    int tries_number = 1;
    int current_try = 0;
    int current_player =1;

    srand(time_val);

    cout << "\tLet's play dice!\n";
    //how many players?
    cout << "How many players? (from 1 to 10): ";
    cin >> players_number;

    // how many dices?
    cout << "How many dices? (from 1 to 10): ";
    cin >> dices_number;

    //how many tries?
    cout << "How many tries? (from 1 to 10): ";
    cin >> tries_number;
    cin.get();

    //PLAY
    do
    {
        for (int j = 1; j <= players_number; ++j)
        {
            cout << "\nPlayer number [" << j << "] should throw the dices " ;
            cout << "\nPress ENTER to throw the dices";
            cin.get();

            int sum = 0;
            for (int i=1; i <= dices_number; ++i)
            {
                int rand_number;
                rand_number = rand() % 6 + 1;
                sum += rand_number;
                cout << " " << rand_number;
            }
            cout << "\tSum = " << sum << endl;
        }
        ++current_try;
    }while(current_try < tries_number);

    //Do you want to repeat? Y/N



    //When No - show statistic




//    cout << "Let's play dice!\n";

//    cout << "Press Enter to begin" << endl;
//    cin.get();
//    for (int i=1; i< 20; ++i)
//    cout << rand() % 6 + 1 << endl;;


//    cout << "Hi";
    return 0;
}
