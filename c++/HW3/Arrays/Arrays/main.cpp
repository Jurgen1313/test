#include <QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <ctime>

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
                        double temp_val;
                        temp_val = arr[i];
                        arr[i] = arr[i+1];
                        arr[i+1] = temp_val;
                }
                F_print_array(array_size, arr);
                system ("pause");
                break;
            }
            case 2: // Bubble sort
            {
                // sorting from min to max
                bool change;
                size_t number_of_changes = 0;
                do
                {
                    change = false;
                    for (uint i = 0; i < array_size - 1; ++i )
                    {
                        if ( arr[i] > arr[i+1])
                        {
                            double temp_val;
                            temp_val = arr[i];
                            arr[i] = arr[i+1];
                            arr[i+1] = temp_val;
                            change = true;
                            ++number_of_changes;
                        }
                    }
                }while(change);

                cout << "\nNumber of changes n = " << number_of_changes << endl;
                F_print_array(array_size, arr);

                // sorting from max to min
                number_of_changes = 0;

                do
                {
                    change = false;
                    for (uint i = 0; i < array_size - 1; ++i )
                    {
                        if ( arr[i+1] > arr[i])
                        {
                            double temp_val;
                            temp_val = arr[i];
                            arr[i] = arr[i+1];
                            arr[i+1] = temp_val;
                            change = true;
                            ++number_of_changes;
                        }
                    }
                }while(change);

                cout << "\nNumber of changes n = " << number_of_changes << endl;
                F_print_array(array_size, arr);
                system ("pause");
                break;
            }
            case 3: // Quicksort (((
            {

//                 cout << "\nSORRY, Algorithm is under construction!!!!\n";
//                 system ("pause");
//                 break;
//                uint element_number;
// //                srand(time(0));

//                cout << "How many elements should array have? : ";
//                element_number = F_is_this_number('u');

//                double arr[element_number];
//                const size_t array_size = sizeof(arr)/sizeof(arr[0]);

//                cout << "Do you want manual input? <Y>es or <N>o : ";

//                if (F_repeat())
//                {
//                    for(uint i = 0; i < array_size; ++i)
//                    {
//                        cout << "Insert number arr[" << i <<"] = ";
//                        arr[i] = F_is_this_number('d');
//                    }
//                }
//                else
//                    for (uint i = 0; i < array_size; ++i)
//                        *(arr + i) = rand();

//                F_print_array(array_size, arr);

                uint middle_val = 0;                        ;
                uint middle_midlle_val = 0;
                 //                int right_val = array_size - 1;
                uint temp_val = array_size - 1;
                int direction = 0;

                do
                {
                    while (middle_val != temp_val)
                    {
                        switch (direction)
                        {
                            case 0:
                            {
                                if (arr[middle_val] > arr[temp_val])
                                {
                                    cout << "Change arr["<< middle_val << "] = " << arr[middle_val] << " with arr[" << temp_val << "] = " << arr[temp_val] << endl;
                                    double temp_buff;
                                    temp_buff = arr[middle_val];
                                    arr[middle_val] = arr[temp_val];
                                    arr[temp_val] = temp_buff;

                                    uint temp_buff_1 = 0;
                                    temp_buff_1 = middle_val;
                                    middle_val = temp_val;
                                    temp_val = temp_buff_1;
                                    direction = 1;
                                    break;
                                }
                                --temp_val;
                                break;
                            }
                            case 1:
                            {
                                if (arr[middle_val] < arr[temp_val])
                                {
                                    cout << "Change arr["<< middle_val << "] = " << arr[middle_val] << "with arr[" << temp_val << "] = " << arr[temp_val] << endl;
                                    double temp_buff;
                                    temp_buff = arr[middle_val];
                                    arr[middle_val] = arr[temp_val];
                                    arr[temp_val] = temp_buff;

                                    uint temp_buff_1 = 0;
                                    temp_buff_1 = middle_val;
                                    middle_val = temp_val;
                                    temp_val = temp_buff_1;
                                    direction = 0;
                                    break;
                                }
                                ++temp_val;
                                break;
                            }
                        }
                    }
//                    F_print_array(array_size, arr);
                    cout << "left_val = " << temp_val << "\tright_val = " << middle_val << endl;
                }while(false);
                F_print_array(array_size, arr);
//                cout << "left part" << "right part" << endl;
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
                bool change;
                size_t number_of_changes = 0;
                do
                {
                    change = false;
                    for (uint i = 0; i < array_size - 1; ++i )
                    {
                        if ( arr[i] > arr[i+1])
                        {
                            double temp_val;
                            temp_val = arr[i];
                            arr[i] = arr[i+1];
                            arr[i+1] = temp_val;
                            change = true;
                            ++number_of_changes;
                        }
                    }
                }while(change);

                F_print_array(array_size, arr);

                // Find my number
                size_t left_val = 0;
                size_t right_val = array_size - 1;
                size_t middle_val = (right_val + left_val) / 2;

                cout << "What number you want me to find? : ";
                double search_val = F_is_this_number('d');

                while ( left_val < right_val)
                {
                    if (arr[middle_val] == search_val)
                    {
                        cout << "I found your value " << search_val << " in the position " << middle_val << endl;
                        if (arr[middle_val + 1] == search_val || arr[middle_val - 1] == search_val)
                            cout << "There are more than 1 equell number in the array!!!!!" << endl;
                        break;
                    }
                    else if (arr[middle_val] < search_val)
                        left_val = middle_val;
                    else
                        right_val = middle_val;

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

