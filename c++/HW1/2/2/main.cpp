#include <iostream>
#include <cmath>

using namespace std;

int input_number;
int digit_count;
int sum = 0;
int temp_var = 0;

int main()
{
    cout << "\t Welcome\n";
    cout << "How many digit numbers do you want to input?\n";
    cout << "n = ";
    cin >> digit_count;
    cout << endl;


    cout << "Type " << digit_count << " digits number : ";
    cin >> input_number;

    for (int i = 0; i < digit_count ; i++)
    {
        sum += input_number % 10;
        input_number = input_number / 10;
    }

    cout << "Sum = " << sum << endl;

    return 0;
}
