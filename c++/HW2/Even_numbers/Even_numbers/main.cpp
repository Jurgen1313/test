#include <QCoreApplication>
#include <cstdlib>
#include <cmath>
#include <iostream>

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
    int left_border;
    int right_boarder;
    int quantity_even = 0;
    int quantity_odd = 0;

    cout << "Give me left boarder : ";
    left_border = F_is_this_number('i');
    cout << "Give me right boarder : ";
    right_boarder = F_is_this_number('i');

    if (left_border >= right_boarder)
    {
        cout << "\n\tWARNING!!!!\n\tLeft boarder should be less then right boarder!!!!!\n";
        return 0;
    }

    cout << "\nThis program prints even number :\n";
    for (; left_border <= right_boarder; ++left_border)
    {
        if (!(left_border % 2))
        {
            cout << left_border << " ";
            ++quantity_even;
        }
        else
            ++quantity_odd;
    }

    cout << "\nQuantity even numbers: " << quantity_even << endl;
    cout << "Quantity odd numbers: " << quantity_odd << endl;
    return 0;
}
