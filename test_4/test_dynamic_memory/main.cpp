#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
//#include <conio.h>

using namespace std;

double F_is_this_number (const char symbol)
{

    int i_number;
    int ui_number;
    double d_number;
    bool negative_val = false;
    size_t size_t_number;

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
                        cout << "Negative value. Retype number : ";
                    }
                    else
                        negative_val = false;
                    break;
                }
            case 's':
                {
                    cin >> size_t_number;
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
            while (cin.get() != '\n');
            cout << "Invalid value. Retype number : ";
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
        case 's':
        {
            return size_t_number;
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
        }
    } while (input_char);
    return cycle;
}

void F_print_array (const int size_array, const double *parray)
{
    cout << endl;
    for (int i = 0; i < size_array; ++i)
        cout << "arr [" << i << "] = " << *(parray + i) << " adress = " <<  parray + i << endl;
//    for (double* q = parray; q != parray + size_array; ++q)
//        cout << " " << *q << " " << q << endl;
}

int main()
{
    srand(time(0));


    int task_number = 0;
    bool keep_asking = true;
    do
    {
        system("cls");
        cout << "\tWellcome to testwork 3 (dynamic memory)" << endl << endl;
        cout << " Choose task : " << endl;
        cout << "<1> Create dynamic array and change it size using NEW & DELETE" << endl;
        cout << "<2> Create dynamic array and change it size using MALLOC, CALLOC, REALLOC" << endl;;
        cout << "<3> Read data until \"0\" " << endl;
        cout << "<4> Combine two strings" << endl;
        cout << "<5> " << endl;
        cout << "<6> EXIT" << endl << endl;
        cout << "Make your choise : " ;

        do
        {
            task_number = F_is_this_number('u');
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

        switch (task_number)
        {
            case 1:
            {
                cout << "How many elements should array have? : ";
                size_t *array_size = new size_t (F_is_this_number('d'));
                double *p_array = new (nothrow) double [*array_size] {0};

                if (!p_array)
                cout << "ERROR creating array" << endl;

                cout << "Do you want manual input? <Y>es or <N>o : ";

                if (F_repeat())
                {
                    for(size_t i = 0; i < *array_size; ++i)
                    {
                        cout << "Insert number arr[" << i <<"] = ";
                        p_array[i] = F_is_this_number('d');
                    }
                }
                else
                    for (size_t i = 0; i < *array_size; ++i)
                        *(p_array + i) = rand();

                F_print_array(*array_size, p_array);

                cout << endl;
                cout << "How many ellements should new array have? :";

                size_t *new_array_size = new size_t (F_is_this_number('d'));
                double *p_copy_array = new double [*new_array_size] {0};
                for (size_t i = 0; i < *new_array_size; ++i)
                {
                    if (i < *array_size )
                        p_copy_array[i] = p_array[i];
                    else
                        p_copy_array[i] = rand();
                }
                F_print_array(*new_array_size, p_copy_array);
                cout << endl;
                cout << "New created array address = " << p_copy_array << "\nOld array address = " << p_array << endl;
                delete[] p_array;
                p_array = 0;
                p_array = p_copy_array;

                p_copy_array = 0;
                delete[] p_copy_array;
//                p_copy_array = 0;

                F_print_array(*new_array_size, p_array);

                if ( p_copy_array != nullptr )
                    for (size_t i = 0; i < *new_array_size; ++i)
                        cout << *(p_copy_array + i) << "  " << p_copy_array + i << endl;

                system("pause");
                // DELETE all dynamic variables (THIS MAY NOT BE DONE!!!!)
                delete[] p_array;
                p_array = 0;
                delete[] p_copy_array;
                p_copy_array = 0;
                delete array_size;
                array_size = 0;
                delete new_array_size;
                new_array_size = 0;
                break;
            }
            case 2:
            {
                cout << "How many elements should array have? : ";
                size_t *array_size = static_cast<size_t*>(malloc(sizeof(int)));
                *array_size = F_is_this_number('i');
//                cout << "\nArray_size = " << *array_size << endl;
                double *p_array = static_cast<double*>(calloc(*array_size, sizeof(double)));

                if (!p_array)
                cout << "ERROR creating array" << endl;

                cout << "Do you want manual input? <Y>es or <N>o : ";

                if (F_repeat())
                {
                    for(size_t i = 0; i < *array_size; ++i)
                    {
                        cout << "Insert number arr[" << i <<"] = ";
                        p_array[i] = F_is_this_number('d');
                    }
                }
                else
                    for (size_t i = 0; i < *array_size; ++i)
                        *(p_array + i) = rand();

                F_print_array(*array_size, p_array);
                cout << endl;
                cout << "How many elements should new array have? :";
                size_t *new_array_size = static_cast<size_t*>(malloc(sizeof(int)));
                *new_array_size = F_is_this_number('i');
                double *p_copy_array = static_cast<double*>(realloc(p_array, *new_array_size * sizeof(double) ));

                cout << "\nNew address = " << p_copy_array << endl;
                p_array = p_copy_array;
                p_copy_array = 0;
                free(p_copy_array);

                if ( *array_size < *new_array_size )
                for (size_t i = *array_size; i < *new_array_size; ++i)
                    *(p_array + i) = rand();
                *array_size = *new_array_size;
                free(new_array_size);

                F_print_array(*array_size, p_array);
                system("pause");
                break;
            }
            case 3:
            {
                size_t buff = 2;
                size_t count = 0;
                char *p_char_array = static_cast<char*>(calloc(buff, sizeof(char)));
                cout << "Input string : " << endl;
//                char input_value = getch();
                char input_value = _getwch();
                cout << input_value;
                while (input_value != '0')
                {
                    if (buff > count)
                    {
                        *(p_char_array + count) = input_value;
                    }
                    else
                    {
                        char *p_new_array = static_cast<char*>(realloc(p_char_array, (++buff) * sizeof(char)));
//                        cout << "\nNew address = " << p_new_array << "   " << *p_new_array << endl;
                        p_char_array = p_new_array;
                        p_new_array = 0;
                        free (p_new_array);
                        *(p_char_array + count) = input_value;
                    }
//                    input_value = getch();
                    input_value = _getwch();
                    ++count;
                    cout << input_value;
                }

                cout << "\nYou entered " << count << " symbols until \'0\'" << endl;
                for (size_t i = 0; i < count; ++i)
                    cout << "array [" << i << "] = " << *(p_char_array + i) << endl;

                cout << "\n string : " << p_char_array << endl;
                system ("pause");
                break;
            }
            case 4:
            {
                size_t buff = 1000;
//                char *first_string = new char[buff];
                char *first_string = static_cast<char*>(calloc(buff, sizeof(char)));
                cout << "\nGive string 1 : ";
                cin.getline(first_string, buff);
//                char *second_string = new char[buff];
                char *second_string = static_cast<char*>(calloc(buff, sizeof(char)));
                cout << "Give string 2 : ";
                cin.getline(second_string, buff);

                size_t string_1_lenght = 0;
                size_t string_2_lenght = 0;
                buff = 0;
                while(*(first_string + (buff++)));
                string_1_lenght = --buff;
                buff = 0;
                while(*(second_string + (buff++)));
                string_2_lenght = --buff;


                cout << "\nFirst string is : " << first_string << " string lenght = " << string_1_lenght << endl;
                cout << "Second string is : " << second_string << " string lenght = " << string_2_lenght << endl;

                //new third string
                char *third_string = static_cast<char*>(calloc(string_1_lenght + string_2_lenght, sizeof(char)));

//                for (size_t i = 0; i < (string_1_lenght + string_2_lenght); ++i)
//                    if ( i < string_1_lenght )
//                        *(third_string + i) = *(first_string + i);
//                    else
//                        *(third_string + i) = *(second_string + i);

                for (size_t i = 0; i < string_1_lenght; ++i)
                        *(third_string + i) = *(first_string + i);
                for (size_t i = 0; i < string_2_lenght; ++i)
                        *(third_string + string_1_lenght + i) = *(second_string + i);

                cout << "\nNew Third string : " << third_string;

                char *split_1_2_string = static_cast<char*>(realloc(first_string, (string_1_lenght + string_2_lenght)* sizeof(char)));
                char *split_2_1_string = static_cast<char*>(realloc(second_string, (string_1_lenght + string_2_lenght) * sizeof(char)));
                if (split_1_2_string == nullptr || split_2_1_string == nullptr )
                    cout << "\n\n\n\nVERY-VERY-VERY BAD\n";
                first_string = split_1_2_string;
                second_string = split_2_1_string;
                cout << "\n1_2 string : " << split_1_2_string;
                cout << "\n2_1 string : " << split_2_1_string;

                for (size_t i = 0; i < string_2_lenght; ++i)
                    *(first_string + string_1_lenght + i) = *(second_string + i);

                for (size_t i = 0; i < string_1_lenght; ++i)
                    *(second_string + string_2_lenght + i) = *(split_1_2_string + i);

                split_1_2_string = 0;
                free(split_1_2_string);

                split_2_1_string = 0;
                free(split_2_1_string);

                cout << "\nNew first string : " << first_string;
                cout << "\nNew second string : " << second_string << endl;
                system ("pause");
                break;
            }
        }
    }while(1);

    return 0;
}
