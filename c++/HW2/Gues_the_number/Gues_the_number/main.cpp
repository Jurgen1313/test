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


int main()
{
//    QCoreApplication a(argc, argv);
    bool play_again = true;
    srand (time(NULL));

//    int L_number = 0;
//    int H_number = 100;


    do
    {
        int L_number = 0;
        int H_number = 100;
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
            if (user_number < L_number || user_number > H_number)
                cout << "\nBe carefull, you should enter the number between " << L_number << " and " << H_number;
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
    }while(play_again);
    return 0;
}
