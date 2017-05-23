#include <iostream>
#include <cmath>

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

int Sum_of_digits (int number)
{
    int sum = 0;

    for (int i = 0; i < pow(2,sizeof(int)*8) ; i++)
    {
        if ( number / 10 >= 1 || number / 10 <= -1 )
        {
            sum += number % 10;
            number /= 10;
        }
        else
        {
            sum += number % 10;
            break;
        }
    }

    if (sum < 0)
        sum *= -1;

    return sum;
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
    int task_number = 0;
    bool keep_asking = true;

    do
    {
        system("cls");
        cout << "\tWellcome to home work 1" << endl << endl;
        cout << " Choose task : " << endl;
        cout << "<1> Find max value" << endl;
        cout << "<2> Find sum of digits in a number" << endl;;
        cout << "<3> Console calculator" << endl;
        cout << "<4> EXIT" << endl << endl;
        cout << "Make your choise : " ;

        do
        {
            task_number = F_is_this_number('i');
            switch (task_number)
            {
                case 1:
                case 2:
                case 3:
                {
                    keep_asking = false;
                    system("cls");
                    break;
                }
                case 4 :
                {
                    return 0;
                    break;
                }
                default:
                {
                    cout << " Retype number : ";
                    keep_asking = true;
                    break;
                }
            }
        }while (keep_asking);


        switch (task_number)
        {
            case 1:
            {
                int input_number;
                int max_number = 0;
                int numbers_count = 0;
                int number_index = 0;

                cout << "\t Welcome o task 1\n";
                cout << "How many integer numbers do you want to input?\n";
                cout << "n = ";
                numbers_count = F_is_this_number('i');
                cout << endl;

                for ( int i = 0; i < numbers_count; i++)
                {
                    cout << " Give me integer number [" << i + 1 << "] = ";
                    input_number = F_is_this_number('i');

                    if ( input_number > max_number )
                    {
                        max_number = input_number;
                        number_index = i +1;
                    }
                }
                cout << "\nThe maximum value is number [" << number_index << "] = " << max_number << "\n\n";
                cout << "Press <ENTER> to return to the main screen";
                cin.get();
                break;
            }
            case 2:
            {
                int input_number;

                cout << "\t Welcome\n";
                cout << " Type int number : ";

                input_number = F_is_this_number('i');

                cout << " You type int number : " << input_number << endl;
                cout << "Sum of all digits in a number " << input_number << " is equel to : " << Sum_of_digits (input_number) << endl << endl;
                cout << "Press <ENTER> to return to the main screen";
                cin.get();
                break;
            }
            case 3:
            {
                char function_type;
                double number_1 = 0, number_2;

                cout << "\t Console calculator" << endl << endl;
                cout << "\n------------------";
                cout << "\n|func      Symbol|";
                cout << "\n------------------";
                cout << "\n| add  ----   +  |";
                cout << "\n| sub  ----   -  |";
                cout << "\n| mul  ----   *  |";
                cout << "\n| div  ----   /  |";
                cout << "\n| pow  ----   p  |";
                cout << "\n| sqrt ----   q  |";
                cout << "\n| sin  ----   s  |";
                cout << "\n| cos  ----   c  |";
                cout << "\n| tan  ----   t  |";
                cout << "\n------------------" << endl;

                cout << "Input number : ";
                number_1 = F_is_this_number('d');
                cout << "Choose function : ";
                function_type = F_is_this_char();

                switch (function_type)
                {
                    case '+':
                    {
                        cout << "Input second number : ";
                        number_2 = F_is_this_number('d');
                        cout << "Result " << number_1 << " + " << number_2 << " is equal to : " << number_1 + number_2 << endl;
                        break;
                    }
                    case '-':
                    {
                        cout << "Input second number : ";
                        number_2 = F_is_this_number('d');
                        cout << "Result " << number_1 << " - " << number_2 << " is equal to : " << number_1 - number_2 << endl;
                        break;
                    }
                    case '*':
                    {
                        cout << "Input second number : ";
                        number_2 = F_is_this_number('d');
                        cout << "Result " << number_1 << " * " << number_2 << " is equal to : " << number_1 * number_2 << endl;
                        break;
                    }
                    case '/':
                    {
                        cout << "Input second number : ";
                        number_2 = F_is_this_number('d');
                        cout << "Result " << number_1 << " / " << number_2 << " is equal to : " << number_1 / number_2 << endl;
                        break;
                    }
                    case 'p':
                    {
                        cout << "Input second number : ";
                        number_2 = F_is_this_number('d');
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
                cout << "\nPress <ENTER> to return to the main screen";
                cin.get();
                break;
            }
        }
    }while(1);
}
