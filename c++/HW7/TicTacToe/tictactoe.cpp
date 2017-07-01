#include "tictactoe.h"

void printField(const int* ttt, const size_t lenght , const int Col)
{
    size_t element = 0;
    for (size_t i = 0; i < lenght; ++i)
    {
        std::cout << "|";//<< ttt[i];
        if (ttt[i] != 10 && ttt[i] != 11)
            std::cout << ttt[i];
        else if (ttt[i] == 10)
            std::cout << "O";
        else
            std::cout << "X";
        ++element;
        if ( element == Col)
        {
            element = 0;
            std::cout << "|" << std::endl;
        }

    }
}

void EmptyField(int* Field, const size_t lenght)
{
    for (size_t i = 0; i < lenght; ++i)
        Field[i] = i +1;
}

int humanNumber(const int* Field)
{
    int cellNumber = 0;
    std::cout << "Put cell number : ";
    std::cin >> cellNumber;
    --cellNumber;
    while (Field[cellNumber] == 10 || Field[cellNumber] == 11)
    {
        std::cout << "Put cell number : ";
        std::cin >> cellNumber;
        --cellNumber;
    }
    return cellNumber;
}

int robotNumber(const int* Field)
{
    int cellNumber;
    cellNumber = rand() % 8;
    while (Field[cellNumber] == 10 || Field[cellNumber] == 11)
    {
        cellNumber = rand() % 8;
    }
    std::cout << "random : " << cellNumber + 1 << std::endl;
    return cellNumber;
}

void whoWin (const int* Field, const size_t lenght, const int Col)
{
    int Winner = 0;
    //Check horizontal
    for (size_t i = 0; i < (lenght - Col); ++i)
    {
        int sumO = 0;
        int sumX = 0;
        for (size_t j = 0; j < Col; ++j)
        {
            if (Field[i + Col * j] == 10)
                ++sumO;
            else if (Field[i + Col * j] == 11)
                ++sumX;
        }
        if (sumO == 3)
        {
            std::cout << "Win OOO" << std::endl;
            Winner = 1;
        }
        if (sumX == 3)
        {
            std::cout << "Win XXX" << std::endl;
            Winner = 1;
        }
    }

    //Check vertical
    for (size_t i = 0; i < (lenght - Col); ++i)
    {
        int sumO = 0;
        int sumX = 0;
        for (size_t j = 0; j < Col; ++j)
        {
            if (Field[j + Col * i] == 10)
                ++sumO;
            else if (Field[j + Col * i] == 11)
                ++sumX;
        }
        if (sumO == 3)
        {
            std::cout << "Win OOO" << std::endl;
            Winner = 1;
        }
        if (sumX == 3)
        {
            std::cout << "Win XXX" << std::endl;
            Winner = 1;
        }
    }

    int sumO = 0;
    int sumX = 0;
    //Check diagonals leftUpper ---> rightLower
    for (size_t i = 0; i < Col; ++i)
    {
        if (Field[i + Col * i] == 10)
            ++sumO;
        else if (Field[i + Col * i] == 11)
            ++sumX;
//        cout << "i : " << i << "  " << Field[i + Col * i] << endl;
        if (sumO == 3)
        {
            std::cout << "Win OOO" << std::endl;
            Winner = 1;
        }
        if (sumX == 3)
        {
            std::cout << "Win XXX" << std::endl;
            Winner = 1;
        }
    }
    sumO = 0;
    sumX = 0;
    //Check diagonals leftLower ---> rightUpper
    for (size_t i = (Col - 1); i < (lenght -1); i += 2)
    {
        if (Field[i] == 10)
            ++sumO;
        else if (Field[i] == 11)
            ++sumX;
//        std::cout << "i : " << i << "  " << Field[i] << std::endl;
        if (sumO == 3)
        {
            std::cout << "Win OOO" << std::endl;
            Winner = 1;
        }
        if (sumX == 3)
        {
            std::cout << "Win XXX" << std::endl;
            Winner = 1;
        }
    }
//    return lenght;
    if (Winner)
        exit(0);
}