/*
 *
 * Program reads five intagers and
 * prints the highest number
 *
*/

#include <iostream>

using namespace std;

int main()
{   
    int input_number;
    int max_number = 0;
    int numbers_count = 0;
    int number_index = 0;

    cout << "\t Welcome\n";
    cout << "How many intager numbers do you want to input?\n";
    cout << "n = ";
    cin >> numbers_count;
    cout << endl;

    for ( int i = 0; i < numbers_count; i++)
    {
        cout << " Give me intager number [" << i + 1 << "] = ";
        cin >> input_number;

        if ( input_number > max_number )
        {
            max_number = input_number;
            number_index = i +1;
        }
    }

    cout << "\nThe maximum value is number [" << number_index << "] = " << max_number << "\n\n";

    return 0;
}
