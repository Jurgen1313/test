#include <QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double F_is_this_number (char symbol)
{

    int i_number;
    double d_number;

    bool keep_asking = true;

    do
    {
        switch (symbol)
        {
        case 'i':
        {
            cin >> i_number;
            break;
        }
        case 'd':
        {
            cin >> d_number;
            break;
        }
        default:
        {
            cout << "INCORRECT SYMBOL";
            break;
        }

        }
        if ( cin.get() != '\n' )
        {
            cin.clear(); // відновлення прапорця функції cin.fail() в стан good
//                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            while (cin.get() != '\n');
            cout << " Retype number : ";
        }
        else
        {
            keep_asking = false;
        }
    }while (keep_asking);

    switch (symbol)
    {
        case 'i':
        {
            return i_number;
            break;
        }
        case 'd':
        {
            return d_number;
            break;
        }
        default:
        {
            cout << "INCORRECT SYMBOL";
            return 1;
            break;
        }
    }
}

bool F_repeat ()
{
    bool cycle;
    char answer;
    bool input_char = true;

    do
    {
        cout << "\nDo you want to repeat?\n";
        cout << "Type <Y>es to repeat or <N>o to exit: ";
        cin >> answer;

        switch (answer)
        {
            case 'Y':
            case 'y':
            {
                input_char = false;
                cycle = true;
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
//            cout << "Type <Y>es to repeat or <N>o to exit: ";
        }
    } while (input_char);
    return cycle;
}

int main()
{
//    QCoreApplication a(argc, argv);

    int time_val = time(0);
    int players_number = 1;
    int player_index = 0;
    int dices_number = 1;
    int tries_number = 1;
    int current_try = 0;
    bool play_again = true;
    int draw_game_count = 0;
    int number_of_wins[100];

    for (int i = 0; i < 100; ++i)
        number_of_wins[i] = 0;

    srand(time_val);

    system("cls");
    cout << "\tLet's play dice!\n";

    //how many players?
    cout << "How many players? (from 1 to 10): ";
    players_number = F_is_this_number('i');

    // how many dices?
    cout << "How many dices? (from 1 to 10): ";
    dices_number = F_is_this_number('i');

    //how many tries?
    cout << "How many tries? (from 1 to 10): ";
    tries_number = F_is_this_number('i');

    do
    {
//        //PLAY
//        int sum_of_number[players_number];
// //        int number_of_wins[players_number];

//        for (int i = 0; i < players_number; ++i)
//        {
//            sum_of_number[i] = 0;
// //            number_of_wins[i] = 0;
//        }

        do
        {
            //PLAY
            int sum_of_number[players_number];

            for (int i = 0; i < players_number; ++i)
                sum_of_number[i] = 0;

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
                        ++draw_game_count;
                        cout << "Draw game\n";
                    }
                    else if (!draw_game && i == player_index)
                    {
                        cout << " WIN ";
                        number_of_wins[i] += 1;
                    }
                    cout << "Player " << i + 1 << "\t with a score " << max << endl;
                }
            ++current_try;
        }while(current_try < tries_number);

        //Do you want to repeat? Y/N
        play_again = F_repeat();
        current_try = 0;

    }while(play_again);

    for (int i = 0; i < players_number; ++i)
    {
        cout << "Player " << i + 1 << "\t wins " << number_of_wins[i] << " times" << endl;
    }
    cout << "Draw game :\t" << draw_game_count << endl;
    cout << "Bye\n";
    return 0;
}
