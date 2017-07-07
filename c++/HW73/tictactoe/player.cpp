#include "player.h"

Player::Player():numberWins(0)
{
    playerMoves = new int[moveNumber] {0};
}

Player::~Player()
{
    delete[] playerMoves;
}

void Player::setPlayerMove(int move, int count)
{
    playerMoves[count - 1] = move + 1;
}

void Player::resetPlayerMoves()
{
    for (size_t i = 0; i < moveNumber; ++i)
        playerMoves[i] = 0;
}

void Player::printPlayerMoves() const
{
    for (size_t i = 0; i < moveNumber; ++i)
    {
        if (playerMoves[i] != 0)
            std::cout << playerMoves[i];
    }
}

size_t Human::move()
{
    size_t cellNumber = 0;
    cellNumber = F_is_this_number ('s');
    return --cellNumber;
}

void Human::Human1Func()
{
    std::cout <<"Human 1 Func";
}

size_t Bot_L1::move()
{
    return rand() % 9;
}

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
