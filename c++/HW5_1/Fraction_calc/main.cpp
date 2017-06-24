#include <iostream>
#include <cctype>
#include <cstdlib>
#include "ufraction.h"

using namespace std;

void rmove_spaces(char* str);
uFraction expr (char* str);
uFraction term (char* str, int& index);
uFraction number (char* str, int& index);

int main()
{
    const int MAX = 80;
    char buffer[MAX] = {0};

    cout << endl;
    cout << "\tWelcome to console fraction calculator " << endl;

    for (;;)
    {
        cin.getline(buffer, sizeof buffer);
        rmove_spaces(buffer);
        if (!buffer[0])
            return 0;
        cout << "\t = " << expr(buffer) << endl;
    }
}

void rmove_spaces(char* str)
{
    int i = 0;
    int j = 0;
    while ((*(str + i) = *(str + j++)))
        if (*(str + i) != ' ')
            i++;
}

uFraction expr (char* str)
{
    uFraction value;
    int index = 0;
    value = term(str, index);
    for (;;)
    {
        switch (*(str + index++))
        {
            case '\0':
            {
                return value;
                break;
            }
            case '+':
            {
                value += term(str, index);
                break;
            }
            case '-':
            {
                value -= term(str, index);
                break;
            }
            default:
                cout << "ERROR in formula" << endl;
                exit(1);
        }
    }
}

uFraction term (char* str, int& index)
{
    uFraction value;
    value = number(str, index);
    while ((*(str + index) == '*') || (*(str + index) == '/'))
    {
        if (*(str + index) == '*')
            value *= number(str, ++index);
        if (*(str + index) == '/')
            value /= number(str, ++index);
    }
    return value;
}

uFraction number (char* str, int& index)
{
    uFraction value {0,1};
    while (isdigit(*(str + index)))
        value.nom =10 * value.nom + (*(str + index++) - '0');
    if (*(str + index) != '|')
        return value;
    ++index;
    value.den = 0;
    while (isdigit(*(str + index)))
        value.den = 10 * value.den + (*(str + index++) - '0');
    return value;
}
