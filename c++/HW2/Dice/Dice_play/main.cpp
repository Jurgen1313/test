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
    int player_index = 0;
    int dices_number = 1;
    int tries_number = 1;
    int current_try = 0;
    bool cycle = true;
    bool input_char= true;
    char answer;

    srand(time_val);

    do
    {
        system("cls");
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
        int sum_of_number[players_number];

        for (int i = 0; i < players_number; ++i)
            sum_of_number[i] = 0;

        do
        {
            for (int j = 0; j < players_number; ++j)
            {
                cout << "\nPlayer number [" << j + 1 << "] should throw the dices " ;
                cout << "\nPress ENTER to throw the dices";
                cin.get();

                for (int i=0; i < dices_number; ++i)
                {
                    int rand_number;
                    rand_number = rand() % 6 + 1;
                    sum_of_number[j] += rand_number;
                    cout << " " << rand_number;
                }
                cout << "\tSum = " << sum_of_number[j] << "\tTry " << current_try + 1 << endl << endl;
            }
            ++current_try;
        }while(current_try < tries_number);

        int max = sum_of_number[0];

        for (int i = 0; i < players_number; ++i)
            if ( max <= sum_of_number[i])
            {
                max = sum_of_number[i];
                player_index = i;
            }

        bool draw_game = false;

        for (int i = 0; i < players_number; ++i)
            if ( max == sum_of_number[i])
            {
                if (!draw_game && i < player_index )
                {
                    draw_game = true;
                    cout << "Draw game\n";
                }
                else if (!draw_game && i == player_index)
                {
                    cout << " WIN ";
                }
                cout << "Player " << i + 1 << "\t with a score " << max << endl;
            }

        //Do you want to repeat? Y/N

        cout << "\nDo you want to repeat?\n";
        cout << "Type <Y>es to repeat or <N>o to exit: ";
        do
        {
            cin >> answer;
            switch (answer)
            {
                case 'Y':
                case 'y':
                {
                    input_char = false;
                    cycle = true;
                    current_try = 0;
                    break;
                }
                case 'N':
                case 'n':
                {
                    cycle = false;
                    input_char = false;
                    break;
                }
            }
            if (cin.get() != '\n')
            {
                while (cin.get() != '\n');
                input_char = true;
                cycle = true;
                cout << "Make correct choise!!!\n";
                cout << "Type <Y>es to repeat or <N>o to exit: ";
            }
        } while (input_char);

    }while(cycle);

    cout << "Bye\n";
    return 0;
}
