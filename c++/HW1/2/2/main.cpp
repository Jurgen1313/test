#include <iostream>
#include <cmath>
#include<limits>
//#include <string>
//#include <cctype>

using namespace std;

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
    return sum;
}

int main()
{    

    int input_number;
    bool cycle = true;
    char answer;
    bool input_char = true;
    const int End_of_Line = 10;
    bool keep_asking = true;

    cout << "\t Welcome\n";

    do
    {
        cout << " Type int number : ";

        do
        {
            cin >> input_number;

            if ( cin.get() != End_of_Line )
            {
                cin.clear(); // відновлення прапорця функції cin.fail() в стан good
//                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                while (cin.get() != '\n');
                cout << " Retype int number : ";
            }
            else
            {
                keep_asking = false;
                cout << "Thx for correct INT number";
            }
        }while (keep_asking);

        cout << " You type int number : " << input_number << endl;
        cout << "Summ of all digits in a number " << input_number << " is equel : " << Sum_of_digits (input_number) << endl;
        cout << "Do you want to repeat?\n";
        cout << "Type <Y>es to repeat or <N>o to exit: ";

        do
        {
            cin >> answer;
            switch (answer)
            {
                case 'Y':
                case 'y':
                {
                    //                        cycle = true;
                    input_char = false;
                    keep_asking = true;
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
            default:
                {

                    break;
                }
            }
            if (cin.get() != End_of_Line)
            {
                cin.clear();
                while (cin.get() != '\n');
                input_char = true;
                cycle = true;
                cout << "Make correct choise!!!\n";
                cout << "Type <Y>es to repeat or <N>o to exit: ";
            }
        } while (input_char);
    }while (cycle);

    return 0;
}
