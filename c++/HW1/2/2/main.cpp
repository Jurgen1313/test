#include <iostream>
#include <cmath>

using namespace std;



int main()
{    

    int input_number;
    int sum = 0;

    cout << "\t Welcome\n";
    cout << " Type uint number : ";
    cin >> input_number;

    if ( input_number >= 0 )
    {
        cout << " You type uint number : " << input_number << endl;

        for (int i = 0; i < pow(2,sizeof(int)*8) ; i++)
        {
            if ( input_number / 10 > 0)
            {
                sum += input_number % 10;
                input_number = input_number / 10;
            }
            else
            {
                sum += input_number % 10;
                break;
            }
        }

        cout << "Summ = " << sum << endl;
    }
    else
    {
        cout << "NOT uint NUMBER!!!!" << endl;
    }

    return 0;
}
