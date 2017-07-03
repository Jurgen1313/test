#include "player.h"

size_t Player::CountPlayer = 0;
size_t Player::countMoves = 0;

bool Player::Move()
{
    const int P1 = 10; // O
    const int P2 = 11; // X
    if(isMove())
    {
        ++countMoves;
        size_t cellNumber = 0;
        switch (PlayerNumber)
        {
            case 1:
            {
                std::cout << "Player " << Number << " : ";
                std::cout << "put cell number : ";
                cellNumber = F_is_this_number ('s');
                break;
            }
            case 0:
            {
                cellNumber = rand() % 9 + 1;
                break;
            }
        }
        --cellNumber;
        switch (PlayerNumber)
        {
            case 1:
            {
                while (Field[cellNumber] == P1 || Field[cellNumber] == P2)
                {
                    std::cout << "Player " << Number << " : ";
                    std::cout << "Put cell number : ";
                    cellNumber = F_is_this_number ('s');
                    --cellNumber;
                }
                break;
            }
            case 0:
            {
                while (Field[cellNumber] == P1 || Field[cellNumber] == P2)
                {
                    cellNumber = rand() % 9 + 1;
                    --cellNumber;
                }
                break;
            }
        }

        std::cout << "Player " << Number << " : Cell [" << cellNumber + 1 << "]" << std::endl;
        playerMoves[countMoves - 1] = cellNumber + 1;

        if (Number == 1)
            Field[cellNumber] = P1;
        else
            Field[cellNumber] = P2;

        if (Win())
        {
            ++PlayerWin;
            countMoves = 0;
            return true;
        }
        else
            return false;
    }
    else
    {
        std::cout << "\nDRAW GAME";
        std::cout << "\nThere are no more moves!!!" << std::endl;
        return true;
    }
}

bool Player::HumanMove()
{
    const int P1 = 10; // O
    const int P2 = 11; // X
    if(isMove())
    {
        size_t cellNumber = 0;
        std::cout << "Put cell number : ";
        cellNumber = F_is_this_number ('s');
        --cellNumber;
        while (Field[cellNumber] == P1 || Field[cellNumber] == P2)
        {
            std::cout << "Put cell number : ";
            cellNumber = F_is_this_number('s');
            --cellNumber;
        }
        if (Number == 1)
            Field[cellNumber] = P1;
        else
            Field[cellNumber] = P2;

        if (Win())
        {
            ++PlayerWin;
            return true;
        }
        else
            return false;
    }
    else
    {
        std::cout << "\nDRAW GAME";
        std::cout << "\nThere are no more moves!!!" << std::endl;
        return true;
    }
}

bool Player::BotMove()
{
    const int P1 = 10; // O
    const int P2 = 11; // X
    if(isMove())
    {
        size_t cellNumber = 0;
        cellNumber = rand() % 9 + 1;
        --cellNumber;
        while (Field[cellNumber] == P1 || Field[cellNumber] == P2)
        {
            cellNumber = rand() % 9 + 1;
            --cellNumber;
        }
        std::cout << "random : " << cellNumber + 1 << std::endl;
        if (Number == 1)
            Field[cellNumber] = P1;
        else
            Field[cellNumber] = P2;

        if (Win())
        {
            ++PlayerWin;
            return true;
        }
        else
            return false;
    }
    else
    {
        std::cout << "\nDRAW GAME";
        std::cout << "\nThere are no more moves!!!" << std::endl;
        return true;
    }
}

bool Player::isMove()
{
    const int P1 = 10; // O
    const int P2 = 11; // X
    for (size_t i = 0; i < fieldLenght; ++i)
        if ( Field[i] != P1 && Field[i] != P2 )
            return true;
    return false;
}

bool Player::Win()
{
    const int P1 = 10; // O
    const int P2 = 11; // X
    size_t n = Col;

    //Check horizontal
    for (size_t i = 0; i < n; ++i)
    {
        int sumO = 0;
        int sumX = 0;
        for (size_t j = 0; j < n; ++j)
        {
            if (Field[i + n * j] == P1)
                ++sumO;
            else if (Field[i + n * j] == P2)
                ++sumX;
        }
        if (sumO == 3 || sumX == 3)
        {
            std::cout << "Win Player " << Number << " !!!! " << std::endl;
            return true;
        }
    }

    //Check vertical
    for (size_t i = 0; i < n; ++i)
    {
        int sumO = 0;
        int sumX = 0;
        for (size_t j = 0; j < n; ++j)
        {
            if (Field[j + n * i] == P1)
                ++sumO;
            else if (Field[j + n * i] == P2)
                ++sumX;
        }
        if (sumO == 3 || sumX == 3)
        {
            std::cout << "Win Player " << Number << " !!!! " << std::endl;
            return true;
        }
    }

    //Check diagonals leftUpper ---> rightLower
    if ((Field[0] == Field[4]) && (Field[4] == Field[8]))
    {
        std::cout << "Win Player " << Number << " !!!! " << std::endl;
        return true;
    }

    //Check diagonals leftLower ---> rightUpper
    if ( (Field[2] == Field[4]) && (Field[4] == Field[6]))
    {
        std::cout << "Win Player " << Number << " !!!! " << std::endl;
        return true;
    }
    return false;
}

void Player::printPlayerMoves() const
{
        for (size_t i = (Number - 1); i < fieldLenght; i+=2)
        {
            if (playerMoves[i])
                std::cout << /*"Player " << Number << "made : " << */playerMoves[i];
            else
                break;
        }
}

void Player::ResetCountMoves()
{
    countMoves = 0;
    for (size_t i = 0; i < fieldLenght; i++)
        playerMoves[i] = 0;
}

void Player::deleteMoves()
{
    delete[] playerMoves;
}

void EmptyField(int* Field, const size_t lenght)
{
    for (size_t i = 0; i < lenght; ++i)
        Field[i] = i +1;
}

void printField(const int* Field, const size_t Row, const size_t Col)
{
    const int P1 = 10; // O
    const int P2 = 11; // X
    size_t element = 0;
    size_t lenght = Row * Col;
    for (size_t i = 0; i < lenght; ++i)
    {
        std::cout << "|";
        if (Field[i] != P1 && Field[i] != P2)
            std::cout << Field[i];
        else if (Field[i] == P1)
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

double Player::F_is_this_number (const char symbol)
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
                    negative_val = false;
                    break;
                }
            case 'd':
                {
                    std::cin >> d_number;
                    negative_val = false;
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
                    if (size_t_number <= 0 || size_t_number > 9)
                    {
                        negative_val = true;
                        std::cout << "Invalid value. Retype number : ";
                    }
                    else
                        negative_val = false;
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
            exit (1);
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
            default:
            {
                std::cout << "Make correct choise : ";
                break;
            }
        }

        if (std::cin.get() != '\n')
        {
            while (std::cin.get() != '\n');
            input_char = true;
            cycle = true;
            std::cout << "Make correct choise!!!\n";
            std::cout << "Make correct choise : ";
        }
    } while (input_char);
    return cycle;
}
