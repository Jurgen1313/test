#include "functions.h"

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
                    std::cin >> i_number;
                    break;
                }
            case 'd':
                {
                    std::cin >> d_number;
                    break;
                }
            case 'u':
                {
                    std::cin >> ui_number;
                    if (ui_number < 0)
                    {
                        negative_val = true;
                        std::cout << "Negative value. Retype number : ";
                    }
                    else
                        negative_val = false;
                    break;
                }
            case 's':
                {
                    std::cin >> size_t_number;
                    break;
                }
            default:
                {
                    std::cout << "INCORRECT SYMBOL";
                    break;
                }
        }
        if ( std::cin.get() != '\n')
        {
            std::cin.clear(); // відновлення прапорця функції cin.fail() в стан good
            while (std::cin.get() != '\n');
            std::cout << "Invalid value. Retype number : ";
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
            std::cout << "INCORRECT SYMBOL";
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
        std::cin >> answer;
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

        if (std::cin.get() != '\n')
        {
            while (std::cin.get() != '\n');
            input_char = true;
            cycle = true;
            std::cout << "Make correct choise!!!\n";
        }
    } while (input_char);
    return cycle;
}

void F_print_array (const int size_array, const double *parray)
{
    std::cout << std::endl;
    for (int i = 0; i < size_array; ++i)
        std::cout << "arr [" << i << "] = " << *(parray + i) << " adress = " <<  parray + i << std::endl;
}

void F_buffer_resize(char *input_string, size_t *buffer)
{
            char *p_new_array = static_cast<char*>(realloc(input_string, (++(*buffer)) * sizeof(char)));
            input_string = 0;
            input_string = p_new_array;
}

double* F_buffer_resize_new (double *tmp_arr, const size_t new_lenght, const size_t old_lenght)
{
    double *new_tmp_array = new double [new_lenght];
    for (size_t i = 0; i < new_lenght; ++i)
    {
        if (i < old_lenght )
            new_tmp_array[i] = tmp_arr[i];
        else
            new_tmp_array[i] = 0;
    }
    delete [] tmp_arr;
    tmp_arr = 0;
    return new_tmp_array;
}

void F_buffer_resize_new_2 (double **tmp_arr, const size_t* const new_lenght, const size_t* const old_lenght)
{
    double *new_tmp_array = new double [*new_lenght];
    for (size_t i = 0; i < *new_lenght; ++i)
    {
        if (i < *old_lenght )
            new_tmp_array[i] = (*tmp_arr)[i];
        else
            new_tmp_array[i] = 0;
    }
    delete [] *tmp_arr;
    *tmp_arr = 0;
    *tmp_arr = new_tmp_array;
}

size_t F_Str_lenght (char *tmp_str)
{
    size_t str_lenght = 0;
    while (tmp_str[str_lenght])
        ++str_lenght;
    return str_lenght;
}

char* F_combine_two_strings (char *str1, char *str2)
{
    size_t str1_len = F_Str_lenght(str1);
    size_t str2_len = F_Str_lenght(str2);

    char *new_arr = new char [str1_len + str2_len + 1];

    for (size_t i = 0; i < str1_len; ++i)
        new_arr[i] = str1[i];
    for (size_t i = str1_len; i < (str1_len + str2_len); ++i)
        new_arr[i] = str2[i - str1_len];

    new_arr[str1_len + str2_len] = '\0';
    return new_arr;
}
