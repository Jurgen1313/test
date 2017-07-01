#include "tictactoe.h"

void printField(const int* ttt, const size_t lenght , const size_t Col)
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
    cellNumber = rand() % 9 + 1;
    --cellNumber;
    while (Field[cellNumber] == 10 || Field[cellNumber] == 11)
    {
        cellNumber = rand() % 9 + 1;
        --cellNumber;
    }
    std::cout << "random : " << cellNumber + 1 << std::endl;
    return cellNumber;
}

int whoWin (int* Field, const size_t lenght, const size_t Col, size_t& Player1Wins_, size_t& Player2Wins_)
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
            std::cout << "Win Player 1" << std::endl;
            ++Player1Wins_;
            Winner = 1;
        }
        if (sumX == 3)
        {
            std::cout << "Win Player 2" << std::endl;
            ++Player2Wins_;
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
            std::cout << "Win Player 1" << std::endl;
            ++Player1Wins_;
            Winner = 1;
        }
        if (sumX == 3)
        {
            std::cout << "Win Player 2" << std::endl;
            ++Player2Wins_;
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
            std::cout << "Win Player 1" << std::endl;
            ++Player1Wins_;
            Winner = 1;
        }
        if (sumX == 3)
        {
            std::cout << "Win Player 2" << std::endl;
            ++Player2Wins_;
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
            std::cout << "Win Player 1" << std::endl;
            ++Player1Wins_;
            Winner = 1;
        }
        if (sumX == 3)
        {
            std::cout << "Win Player 2" << std::endl;
            ++Player2Wins_;
            Winner = 1;
        }
    }
    if (Winner)
    {
        std::cout << "Player 1 Wins " << Player1Wins_ << " times\n";
        std::cout << "Player 2 Wins " << Player2Wins_ << " times\n";
//        exit(0);
        EmptyField(Field,lenght);
        return 1;
    }
    return 0;
}

void choosePlayer (int& Player1_, int& Player2_)
{
    char userChoise;
    std::cout << "Now it's time to choose PLAYER 1 :\n";
    std::cout << "type <H> - human or <B> - bot : ";
    std::cin >> userChoise;
    switch (userChoise)
    {
        case 'h':
        case 'H':
        {
            Player1_ = 1;
            break;
        }
        case 'b':
        case 'B':
        {
            Player1_ = 0;
            break;
        }
    }
    std::cout << "Now it's time to choose PLAYER 2 :\n";
    std::cout << "type <H> - human or <B> - bot : ";
    std::cin >> userChoise;
    switch (userChoise)
    {
        case 'h':
        case 'H':
        {
            Player2_ = 1;
            break;
        }
        case 'b':
        case 'B':
        {
            Player2_ = 0;
            break;
        }
    }

    system("cls");
}
