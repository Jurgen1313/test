#include "field.h"

size_t playerField::countMoves = 0;//

playerField::playerField(): Row(3), Col(3), fieldLenght(Row*Col), PlayerNumber(0)
{
    Field = new int [fieldLenght] {1,2,3,4,5,6,7,8,9};
    PlayerNumber = 1;
}

playerField::~playerField()
{
    delete[] Field;
}

int playerField::getPlayerNumber() const
{
    return PlayerNumber;
}

bool playerField::isMove()
{
    if (countMoves == fieldLenght)
    {
        PlayerNumber = 0;
        countMoves = 0;
        return false;
    }
    if (!Win())
        return true;
    else
        return false;
}

bool playerField::Win()
{
    int P = 0;;
    switch (PlayerNumber)
    {
        case 1:
        {
            P = 10; // O
            break;
        }
        case 2:
        {
            P = 11; // X
            break;
        }
    }

    //Check horizontal
    for (size_t i = 0; i < Row; ++i)
    {
        size_t sum = 0;
        for (size_t j = 0; j < Col; ++j)
        {
            if (Field[i + Col * j] == P)
                sum = j;
            else
                break;
        }
        if (sum == Col -1)
        {
//            std::cout << "Win Player " << PlayerNumber << " !!!! " << std::endl;
            return true;
        }
    }

    //Check vertical
    for (size_t i = 0; i < Row; ++i)
    {
        int sum = 0;
        for (size_t j = 0; j < Col; ++j)
        {
            if (Field[j + Col * i] == P)
                ++sum;
        }
        if (sum == 3)
        {
//            std::cout << "Win Player " << PlayerNumber << " !!!! " << std::endl;
            return true;
        }
    }

    //Check diagonals leftUpper ---> rightLower
    if ((Field[0] == Field[4]) && (Field[4] == Field[8]))
    {
//        std::cout << "Win Player " << PlayerNumber << " !!!! " << std::endl;
        return true;
    }

    //Check diagonals leftLower ---> rightUpper
    if ( (Field[2] == Field[4]) && (Field[4] == Field[6]))
    {
//        std::cout << "Win Player " << PlayerNumber << " !!!! " << std::endl;
        return true;
    }
    return 0;
}

void playerField::ResetField()
{
    for (size_t i = 0; i < fieldLenght; ++i)
            Field[i] = i+1;

}

void playerField::PlayerMove(int cellNumber)
{
    const int P1 = 10; // O
    const int P2 = 11; // X
    bool playerWin;
    if (Field[cellNumber] != P1 && Field[cellNumber] != P2)
    {
        ++countMoves;
        std::cout << "\nCountMoves = " << countMoves;
        std::cout << "\nfieldNumber = " << fieldLenght;
        switch (PlayerNumber)
        {
        case 1:
        {
            Field[cellNumber] = P1;
            break;
        }
        case 2:
        {
            Field[cellNumber] = P2;
            break;
        }
        }
        playerWin = Win();
        if (!playerWin)
        {
            ++PlayerNumber;
            if (PlayerNumber == 3)
                PlayerNumber = 1;
        }
    }
}

std::ostream& operator<< (std::ostream& os, const playerField& field)
{
    const int P1 = 10; // O
    const int P2 = 11; // X
    for (size_t i = 0; i < field.Row; ++i)
    {
        os << "\n";
        for (size_t j = 0; j < field.Col; ++j)
        {
            os << " | ";
            if (field.Field[j+field.Col*i] != P1 && field.Field[j+field.Col*i] != P2)
                os << field.Field[j+field.Col*i];
            else if (field.Field[j+field.Col*i] == P1)
                os << "O";
            else
                os << "X";
        }
        os << " | ";
    }
    return os;
}

