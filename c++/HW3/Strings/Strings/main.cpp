#include <QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <iomanip>

using namespace std;

double F_is_this_number (char symbol)
{

    int i_number;
    int ui_number;
    double d_number;
    bool negative_val = false;

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
            case 'u':
                {
                    cin >> ui_number;
                    if (ui_number < 0)
                    {
                        negative_val = true;
                        cout << " Retype number : ";
                    }
                    else
                        negative_val = false;
                    break;
                }
            default:
                {
                    cout << "INCORRECT SYMBOL";
                    break;
                }
        }
        if ( cin.get() != '\n')
        {
            cin.clear(); // відновлення прапорця функції cin.fail() в стан good
//                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            while (cin.get() != '\n');
            cout << " Retype number : ";
        }
        else
        {
            if (!negative_val)
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
        case 'u':
        {
            return ui_number;
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
//        cout << "\nDo you want to repeat?\n";
//        cout << "Type <Y>es to repeat or <N>o to exit: ";
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

void F_print_array (uint size_array, double *parray)
{
    cout << endl;
    for (uint i = 0; i < size_array; ++i)
        cout << "arr [" << i << "] = " << *(parray + i) << endl;
}


int main()
{
    srand(time(0));
    int task_number = 0;
    bool keep_asking = true;

    do
    {
        system("cls");
        cout << "\tWellcome to homework 3" << endl << endl;
        cout << " Choose task : " << endl;
        cout << "<1> Find string lenght" << endl;
        cout << "<2> String compare 1" << endl;;
        cout << "<3> String compare 2" << endl;
        cout << "<4> Revers word order" << endl;
        cout << "<5> EXIT" << endl << endl;
        cout << "Make your choise : " ;

        do
        {
            task_number = F_is_this_number('i');
            switch (task_number)
            {
                case 1:
                case 2:
                case 3:
                case 4:
                {
                    keep_asking = false;
                    system("cls");
                    break;
                }
                case 5:
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
            case 1: // Find string lenght
            {
                const size_t string_lenght = 1000;
                char user_string[string_lenght];
                size_t element_number = 0;
                cout << "Enter your text : ";

                do
                {
                    cin >> user_string;
                    size_t element = 0;
                    while (user_string[element++]);
                    element_number += element;
                }while(cin.get() != '\n');

                --element_number;
                cout << "Your string lenght is: " << element_number << endl;
                cout << "Your string is: " << user_string << endl;

                cout << "\n\nEnter your text : ";
                cin.getline(user_string, string_lenght);
                size_t element = 0;
                while (user_string[element++]);
                cout << "Your string lenght is: " << --element << endl;
                cout << "Your string is:<!>" << user_string << "<!>" << endl;

                system ("pause");
                break;
            }
            case 2: // String compare 1
            {
                const size_t string_lenght = 1000;
                char user_string_1[string_lenght];
                char user_string_2[string_lenght];
                cout << "Enter your text1 : ";
                cin.getline(user_string_1, string_lenght);
                cout << "Enter your text2 : ";
                cin.getline(user_string_2, string_lenght);
                bool equal_strings = true;

                size_t element_number = 0;
                while (user_string_1[element_number++] && equal_strings)
                    equal_strings = equal_strings && (user_string_1[element_number] == user_string_2[element_number]);

                if (equal_strings)
                    cout << "Strings are equal\n";
                else
                    cout << "Strings are not equal\n";

                cout << "\nFirst string  :  " << user_string_1;
                cout << "\nSecond string :  " << user_string_2 << endl;
                system ("pause");
                break;
            }
            case 3: // String compare 2
            {
                system ("pause");
                break;
            }
            case 4: // Revers word order
            {
                const size_t string_lenght = 1000;
                char user_string[string_lenght];
//                size_t element_number = 0;
                cout << "Enter your text : ";

                do
                {
                    cin >> user_string;
                    size_t element = 0;
                    while (user_string[element++]);
                    while (element-- != 0)
                        cout << user_string[element];
                }while(cin.get() != '\n');
                cout << endl;

                system ("pause");
                break;
            }
        }
    }while(1);

    return 0;
}

