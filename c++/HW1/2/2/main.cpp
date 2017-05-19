#include <iostream>
#include <cmath>

using namespace std;

int input_number;
int digit_count = 0;
int digit_count_check = 0;
int sum = 0;
int temp_var = 0;

int main()
{    
    cout << "\t Welcome\n";
    cout << "How many digit numbers do you want to input?\n";
    cout << "the number should be uint n = ";
    cin >> digit_count;
    cout << endl;


    cout << "Type " << digit_count << " digits number : ";
    cin >> input_number;

    temp_var = input_number / 10;

    for (int i = 0; i < pow(2,sizeof(int)*8); i++)
    {
        if ( temp_var > 0)
        {
            digit_count_check++;
            temp_var /= 10;
        }
        else
        {
            digit_count_check++;
            break;
        }

    }
//    cout << "digit in a number = " << digit_count_check << endl;

    if ( digit_count_check == digit_count )
    {
        for (int i = 0; i < digit_count ; i++)
        {
            sum += input_number % 10;
            input_number = input_number / 10;
        }

        cout << "Sum = " << sum << endl;
    }
    else
    {
        cout << "You gave wrong number" << endl;
    }

    return 0;
}
