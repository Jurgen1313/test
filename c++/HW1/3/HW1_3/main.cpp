/*
 * Console calculator
 */

#include <iostream>
#include <cmath>

using namespace std;

double F_is_this_number ()
{
    double number;
    bool keep_asking = true;

    do
    {
        cin >> number;
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

    return number;
}

char F_is_this_char ()
{
    char input_symbol;
    bool keep_asking = true;

    do
    {
        cin >> input_symbol;
        switch (input_symbol)
        {
            case '+':
            case '-':
            case '*':
            case '/':
            case 'p':
            case 's':
            case 'c':
            case 't':
            case 'q':
            {
                if ( cin.get() != '\n' )
                {
                    while (cin.get() != '\n');
                    cout << " Retype symbol : ";
                }
                else
                {
                    keep_asking = false;
                }
                break;
            }
            default:
            {
                while (cin.get() != '\n');
                cout << " Retype symbol : ";
                break;
            }
        }
    }while (keep_asking);

    return input_symbol;
}

int main()
{
//    char add_sign = '+';
//    char minus_sign = '-';
//    char multiply_sign = '*';
//    char divide_sign = '/';
//    char power_2_sign = 'p';
//    char sin_sign = 's';
//    char cos_sign = 'c';
//    char tan_sign = 't';
//    char sqrt_sign = 'q';
    char function_type;
    bool cycle = true;
    double number_1 = 0, number_2;
    char answer;
    bool input_char = true;

    do
    {
        cout << "Console calculator" << endl;
        cout << "Input number : ";
        number_1 = F_is_this_number();
        cout << "Choose function : ";
        function_type = F_is_this_char();

        switch (function_type)
        {
            case '+':
            {
                cout << "Input second number : ";
                number_2 = F_is_this_number();
                cout << "Result " << number_1 << " + " << number_2 << " is equal to : " << number_1 + number_2 << endl;
                break;
            }
            case '-':
            {
                cout << "Input second number : ";
                number_2 = F_is_this_number();
                cout << "Result " << number_1 << " - " << number_2 << " is equal to : " << number_1 - number_2 << endl;
                break;
            }
            case '*':
            {
                cout << "Input second number : ";
                number_2 = F_is_this_number();
                cout << "Result " << number_1 << " * " << number_2 << " is equal to : " << number_1 * number_2 << endl;
                break;
            }
            case '/':
            {
                cout << "Input second number : ";
                number_2 = F_is_this_number();
                cout << "Result " << number_1 << " / " << number_2 << " is equal to : " << number_1 / number_2 << endl;
                break;
            }
            case 'p':
            {
                cout << "Input second number : ";
                number_2 = F_is_this_number();
                cout << "Result " << number_1 << " ^ " << number_2 << " is equal to : " << pow (number_1,number_2) << endl;
                break;
            }
            case 's':
            {
                cout << "Result sin( " << number_1 << " ) is equal to : " << sin(number_1*M_PI/180) << endl;
                break;
            }
            case 'c':
            {
                cout << "Result cos( " << number_1 << " ) is equal to : " << cos(number_1*M_PI/180) << endl;
                break;
            }
            case 't':
            {
                cout << "Result tan( " << number_1 << " ) is equal to : " << tan(number_1*M_PI/180) << endl;
                break;
            }
            case 'q':
            {
                cout << "Result sqrt( " << number_1 << " ) is equal to : " << sqrt(number_1) << endl;
                break;
            }
        }
        cout << "Do you want to repeat?\n";
        cout << "Type <Y>es to repeat or <N>o to exit: ";

        do
        {
            answer = cin.get();
            if (cin.get() != '\n' )
            {
                while (cin.get() != '\n');
                input_char = true;
                cout << "Make correct choise!!!\n";
                cout << "Type <Y>es to repeat or <N>o to exit: ";
            }
            else
            {
                switch (answer)
                {
                    case 'Y':
                    case 'y':
                    {
                        input_char = false;
                        system("cls");
                        break;
                    }
                    case 'N':
                    case 'n':
                    {
                        cycle = false;
                        input_char = false;
                        break;
                    }
                    default :
                    {
                        input_char = true;
                        cout << "Make correct choise!!!\n";
                        cout << "Type <Y>es to repeat or <N>o to exit: ";
                        break;
                    }
                }
            }
        } while (input_char);
    }while (cycle);

        cout << "Goodby" << endl;

    return 0;
}
