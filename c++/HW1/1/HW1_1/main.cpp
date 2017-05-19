/*
 *
 * Program reads five intagers and
 * prints the highest number
 *
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{   
    int input_number;
    int max_number = 0;
    int numbers_count = 0;
    int number_index = 0;

    cout << "\t Welcome\n";
    cout << "How many integer numbers do you want to input?\n";
    cout << "n = ";
    cin >> numbers_count;
    cout << endl;

    for ( int i = 0; i < numbers_count; i++)
    {
        cout << " Give me integer number [" << i + 1 << "] = ";
        cin >> input_number;
//        cout << input_number << "\n";


        while( cin.fail() ) // if the input number is not digit
        {
            cout << input_number << "\n";
            cout << "Error. Please give me integer number\n";
            cin.clear();
            cin.ignore(256,'\n');
            cout << " Give me integer number [" << i + 1 << "] = ";
            cin >> input_number;

        }

        if ( input_number > max_number )
        {
            max_number = input_number;
            number_index = i +1;
        }
    }

    cout << "\nThe maximum value is number [" << number_index << "] = " << max_number << "\n\n";

    return 0;
}
