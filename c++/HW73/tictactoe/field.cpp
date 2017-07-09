#include "field.h"

size_t playerField::countMoves = 0;//

playerField::playerField(): Row(3), Col(3), fieldLenght(Row*Col)
{
    Field = new int [fieldLenght] {1,2,3,4,5,6,7,8,9};
}

playerField::~playerField()
{
    delete[] Field;
}

//int playerField::player1ID() const
//{
//    return Player_1;
//}

//int playerField::player2ID() const
//{
//    return Player_2;
//}

bool playerField::isMove()
{
    if (countMoves == fieldLenght)
    {
        countMoves = 0;
        return false;
    }
    return true;
}

bool playerField::Win(int playerID)
{

    //Check horizontal
    for (size_t i = 0; i < Row; ++i)
    {
        size_t sum = 0;
        for (size_t j = 0; j < Col; ++j)
        {
            if (Field[i + Col * j] == playerID)
                ++sum;
        }
        if (sum == 3)
            return true;
    }

    //Check vertical
    for (size_t i = 0; i < Row; ++i)
    {
        size_t sum = 0;
        for (size_t j = 0; j < Col; ++j)
            if (Field[j + Col * i] == playerID)
                ++sum;
        if (sum == 3)
            return true;
    }

    //Check diagonals leftUpper ---> rightLower
    if ((Field[0] == Field[4]) && (Field[4] == Field[8]))
        return true;

    //Check diagonals leftLower ---> rightUpper
    if ( (Field[2] == Field[4]) && (Field[4] == Field[6]))
        return true;
    return 0;
}

void playerField::ResetField()
{
    for (size_t i = 0; i < fieldLenght; ++i)
        Field[i] = i+1;
    countMoves = 0;

}

bool playerField::PlayerMove(int cellNumber, int playerID)
{
    if (cellNumber < fieldLenght && cellNumber >= 0 &&
            Field[cellNumber] != Player_1 && Field[cellNumber] != Player_2)
    {
        ++countMoves;
        std::cout << "Player[" << cellNumber + 1 << "]";
        Field[cellNumber] = playerID;
        return true;
    }
    return false;
}

std::ostream& operator<< (std::ostream& os, const playerField& field)
{
    for (size_t i = 0; i < field.Row; ++i)
    {
        os << "\n";
        for (size_t j = 0; j < field.Col; ++j)
        {
            os << " | ";
            if (field.Field[j+field.Col*i] != Player_1 && field.Field[j+field.Col*i] != Player_2)
                os << field.Field[j+field.Col*i];
            else if (field.Field[j+field.Col*i] == Player_1)
                os << "O";
            else
                os << "X";
        }
        os << " | ";
    }
    return os;
}

