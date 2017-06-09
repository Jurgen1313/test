#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
//#include <cstdlib>

double F_is_this_number (const char symbol);

void F_print_array (const int size_array, const double *parray);

void F_buffer_resize(char *input_string, size_t *buffer);

double* F_buffer_resize_new (double *tmp_arr, const size_t new_lenght, const size_t old_lenght);

void F_buffer_resize_new_2 (double **tmp_arr, const size_t* const new_lenght, const size_t* const old_lenght);

size_t F_Str_lenght (char *tmp_str);

char* F_combine_two_strings (char *str1, char *str2);

bool F_repeat (void);

#endif // FUNCTIONS_H
