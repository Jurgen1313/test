#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cstring>
#include "functions.h"

using namespace std;

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
//        cout << "<5> " << endl;
        cout << "<5> EXIT" << endl << endl;
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
//                case 5:
                {
                    keep_asking = false;
                    system("cls");
                    break;
                }
                case 5:
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
                double *p_array = new double [*array_size] {0};

                if (!p_array)
                cout << "ERROR creating array" << endl;

                cout << "Do you want manual input? <Y>es or <N>o : ";

                if (F_repeat())
                    for(size_t i = 0; i < *array_size; ++i)
                    {
                        cout << "Insert number arr[" << i <<"] = ";
                        p_array[i] = F_is_this_number('d');
                    }
                else
                    for (size_t i = 0; i < *array_size; ++i)
                        *(p_array + i) = rand();

                F_print_array(*array_size, p_array);

                cout << endl;
                cout << "How many ellements should new array have? :";

                size_t *new_array_size = new size_t (F_is_this_number('d'));

//                p_array = F_buffer_resize_new(p_array, *new_array_size, *array_size);
                F_buffer_resize_new_2(&p_array, new_array_size, array_size);

                cout << "\n new address = " << p_array <<endl;
                F_print_array(*new_array_size, p_array);

                delete[] p_array;
                p_array = 0;
                delete array_size;
                array_size = 0;
                delete new_array_size;
                new_array_size = 0;
                system("pause");
                break;
            }
            case 2:
            {
                cout << "How many elements should array have? : ";
                size_t *array_size = static_cast<size_t*>(malloc(sizeof(int)));
                *array_size = F_is_this_number('i');
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
                    *(p_array + i) = 0;
                *array_size = *new_array_size;
                free(new_array_size);

                F_print_array(*array_size, p_array);
                system("pause");
                break;
            }
            case 3:
            {
                size_t buff = 2;
                size_t num = 0;
                char *p_char_array = static_cast<char*>(calloc(buff, sizeof(char)));
                cout << "Input string : " << endl;
                char input_value = _getwch();
                cout << input_value;

                while (input_value != '0')
                {
                    if ( buff <= strlen(p_char_array) )
                        F_buffer_resize(p_char_array, &buff);
                    *(p_char_array + num) = input_value;
                    input_value = _getwch();
                    cout << input_value;
                    ++num;
                }
                    *(p_char_array + num) = '\0';
                cout << "\nString size is " << (strlen(p_char_array) + 1) << " symbols and you entered " << num << " symbols until \'0\'" << endl;
                cout << "\n string : " << p_char_array << " address = " << &p_char_array << endl;

                cout << "\n string : ";
                for (size_t i = strlen(p_char_array); i > 0; --i)
                    cout << p_char_array [i - 1];

                cout << endl;
                system ("pause");
                free(p_char_array);
                p_char_array = 0;
                break;
            }
            case 4:
            {
                size_t buff = 1000;
                char *first_string = new char [buff];
                cout << "Give me string 1 : ";
                cin.getline(first_string, buff);
                char *second_string = new char [buff];
                cout << "Give me string 2 : ";
                cin.getline(second_string, buff);

                size_t str_1_lenght = F_Str_lenght (first_string);
                size_t str_2_lenght = F_Str_lenght (second_string);

                cout << "\nFirst string lenght = " << str_1_lenght;
                cout << "\nSecond string lenght = " << str_2_lenght << endl;

                char *third_string;

                third_string = F_combine_two_strings(first_string, second_string);
                size_t str_3_lenght = F_Str_lenght (third_string);

                cout << "\nNew Third string : " << third_string << " string lenght = " << str_3_lenght << endl;

                delete[] first_string;
                first_string = 0;
                delete[] second_string;
                second_string = 0;
                delete[] third_string;
                third_string = 0;

                system ("pause");
                break;
            }
        }
    }while(1);

    return 0;
}
