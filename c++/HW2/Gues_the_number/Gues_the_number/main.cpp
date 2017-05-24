//#include <QCoreApplication>
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
    bool play_again = true;
    srand (time(NULL));

    do
    {
        int L_number = 1;
        int H_number = 101;
        int user_number;
        int attempt = 0;
        bool try_again = true;
        system("cls");
        cout << "\tLet's gues number!!!\n";
        int true_number = rand() % 100 + 1;

        do
        {
            cout << "\nTry to gues what number i have? : ";
            user_number = F_is_this_number('i');
            if (user_number <= L_number)
                cout << "\nI told you the number should be greater then " << L_number;
            else if (user_number >= H_number)
                cout << "\nI told you the number should be less then " << H_number;
            else if (user_number == true_number)
            {
                cout << "\nYou win!!! My number is " << true_number;
                try_again = false;
            }
            else if (user_number > true_number)
            {
                cout << "\nMy number is less then " << user_number;
                H_number = user_number;
            }
            else
            {
                cout << "\nMy number is bigger then " << user_number;
                L_number = user_number;
            }
            attempt++;
        }while(try_again);
        cout << "\nAttempt : " << attempt;
        cin.get();
        play_again = F_repeat();
    }while(play_again);
    return 0;
}
