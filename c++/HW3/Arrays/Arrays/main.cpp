#include <QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

uint ccc = 0;

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

void Quicksorf_alg (double *parray, int left_val, int right_val )
{
        ++ccc;
    int dir = 0;
    int lv = left_val;
    int rv = right_val;
    bool left_denied = true;
    bool right_denied = true;

        while (left_val != right_val)
        {
            switch (dir)
            {
                case 0:
                {
                    if (*(parray + left_val) > *(parray + right_val))
                    {
                        cout << "Change arr["<< left_val << "] = " << *(parray + left_val) << " with arr[" << right_val << "] = " << *(parray + right_val) << endl;
                        double temp_buff;
                        temp_buff = *(parray + left_val);
                        *(parray + left_val) = *(parray + right_val);
                        *(parray + right_val) = temp_buff;

                        uint temp_buff_1 = 0;
                        temp_buff_1 = left_val;
                        left_val = right_val;
                        right_val = temp_buff_1;
                        dir = 1;
                        break;
                    }
                    --right_val;
                    break;
                }
                case 1:
                {
                    if (*(parray + left_val) < *(parray + right_val))
                    {
                        cout << "Change arr["<< left_val << "] = " << *(parray + left_val) << "with arr[" << right_val << "] = " << *(parray + right_val) << endl;
                        double temp_buff;
                        temp_buff = *(parray + left_val);
                        *(parray + left_val) = *(parray + right_val);
                        *(parray + right_val) = temp_buff;

                        uint temp_buff_1 = 0;
                        temp_buff_1 = left_val;
                        left_val = right_val;
                        right_val = temp_buff_1;
                        dir = 0;
                        break;
                    }
                    ++right_val;
                    break;
                }
            }
        }
        cout << "Median = " << left_val  << endl;

        if  ( left_val == right_val && (left_val != lv))
        {
            Quicksorf_alg (parray, lv, rv);
//            Quicksorf_alg (parray, left_val + 1, rv);
        }
        else if (left_val == right_val && (left_val != rv))
            Quicksorf_alg (parray, lv+1, rv);
}

void BubbleSort_min_max(double *arr, const size_t array_size)
{
    // sorting from min to max
    bool change = true;
    size_t number_of_changes = 0;
    for (uint j = 1; (j <= array_size) && change; ++j)
    {
        change = false;
        for (uint i = 0; i < (array_size - j); ++i )
        {
            if ( arr[i] > arr[i+1] )
            {
                swap (arr[i],arr[i+1]);
                change = true;
                ++number_of_changes;
            }
        }
    }
}

void BubbleSort_max_min(double *arr, const size_t array_size)
{
    // sorting from min to max
    bool change = true;
    size_t number_of_changes = 0;
    for (uint j = 1; (j <= array_size) && change; ++j)
    {
        change = false;
        for (uint i = 0; i < (array_size - j); ++i )
        {
            if ( arr[i] < arr[i+1] )
            {
                swap (arr[i],arr[i+1]);
                change = true;
                ++number_of_changes;
            }
        }
    }
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
        cout << "<1> Create array" << endl;
        cout << "<2> Bubble sorting" << endl;;
        cout << "<3> Quicksort" << endl;
        cout << "<4> Search element" << endl;
        cout << "<5> Binary search" << endl;
        cout << "<6> EXIT" << endl << endl;
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
                case 5:
                {
                    keep_asking = false;
                    system("cls");
                    break;
                }
                case 6:
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

        uint element_number;
        cout << "How many elements should array have? : ";
        element_number = F_is_this_number('u');

        double arr[element_number] = {0};
        const size_t array_size = sizeof(arr)/sizeof(arr[0]);

        cout << "Do you want manual input? <Y>es or <N>o : ";

        if (F_repeat())
        {
            for(uint i = 0; i < array_size; ++i)
            {
                cout << "Insert number arr[" << i <<"] = ";
                arr[i] = F_is_this_number('d');
            }
        }
        else
            for (uint i = 0; i < array_size; ++i)
                *(arr + i) = rand();

        F_print_array(array_size, arr);

        switch (task_number)
        {
            case 1: // Change even elements with odd elements
            {
                for (uint i = 0; i < array_size - 1; i += 2)
                {
                    swap (arr[i], arr[i+1]);
                }
                F_print_array(array_size, arr);
                system ("pause");
                break;
            }
            case 2: // Bubble sort
            {
                // sorting from min to max
                BubbleSort_min_max(arr, array_size);
                F_print_array(array_size, arr);

                BubbleSort_max_min(arr, array_size);
                F_print_array(array_size, arr);
                system ("pause");
                break;
            }
            case 3: // Quicksort (((
            {
                Quicksorf_alg (arr, 0, array_size - 1);
                F_print_array(array_size, arr);
                cout << "\n\n NUMBER = " << ccc << endl;
                system ("pause");
                break;
            }
            case 4: // Search element in array
            {
                double find_number;
                bool find = false;
                cout << "\nType number which you want to find in array : ";
                find_number = F_is_this_number('d');

                for (uint i = 0; i < array_size; ++i)
                {
                    if ( arr[i] == find_number)
                    {
                        cout << "Found number " << find_number << " in the position " << i << endl;
                        find = true;
                    }
                }

                if (!find)
                    cout << "I couldn't find number " << find_number << " in the array" <<endl;

                system ("pause");
                break;
            }
            case 5: // Binary search
            {
                // sorting from min to max
                BubbleSort_min_max(arr, array_size);
                F_print_array(array_size, arr);

                // Find my number
                size_t left_val = 0;
                size_t right_val = array_size - 1;
                size_t middle_val = (right_val + left_val) / 2;

                cout << "What number you want me to find? : ";
                double search_val = F_is_this_number('d');

                while ( left_val <= right_val)
                {
                    if (arr[middle_val] == search_val)
                    {
                        cout << "I found your value " << search_val << " in the position " << middle_val << endl;
                        if (arr[middle_val + 1] == search_val || arr[middle_val - 1] == search_val)
                            cout << "There are more than 1 equell number in the array!!!!!" << endl;
                        break;
                    }
                    else if (arr[middle_val] < search_val)
                        left_val = middle_val + 1;
                    else
                        right_val = middle_val - 1;

                    middle_val = (right_val + left_val) / 2;
                }

                if ( left_val == right_val && arr[left_val] != search_val)
                    cout << ":( There are now number in the array!!!" << endl;
                system ("pause");
                break;
            }
        }
    }while(1);

    return 0;
}

