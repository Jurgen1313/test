#include <iostream>
#include "field.h"
#include "player.h"

using namespace std;

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

bool ChoosePlayer()
{
    char userChoise;
    cout << "\nType <H>uman or <B>ot : ";
    bool input_char = true;
    bool choise;

    do
    {
        std::cin >> userChoise;
        switch (userChoise)
        {
        case 'H':
        case 'h':
        {
            input_char = false;
            choise = true;
            break;
        }
        case 'B':
        case 'b':
        {
            input_char = false;
            choise = false;
            break;
        }
        }

        if (cin.get() != '\n')
        {
            while (cin.get() != '\n');
            input_char = true;
            cout << "Make correct choise : ";
        }
    } while (input_char);
    return choise;
}

int main()
{
    int time_val = time(NULL);
    srand(time_val);

    playerField Board;
    cout << Board;

    Player *P1 = nullptr;
    Player *P2 = nullptr;
    Player *player = nullptr;
    pID playerID;

    for (;;)
    {
        system("cls");
        cout << "\n\tWelcome to Tic Tac Toe game";
        cout << "\n\tStart the game";
        cout << "\n\tType <Y>es to start or <N>o to quit";
        cout << "\nMake your choise : ";

        if (!F_repeat())
            return 0;
        else
        {
            if (ChoosePlayer())
                P1 = new Human();
            else
                P1 = new Bot_L1();

            if (ChoosePlayer())
                P2 = new Human();
            else
                P2 = new Bot_L1();
            cout << "\n" << Board;
        }
        for (;;)
        {
            int numberPlayer = 1;
            for (;;)
            {
                if (!Board.isMove())
                {
                    cout << "\nDRAW GAME\n";
                    break;
                }
                switch (numberPlayer)
                {
                    case 1:
                    {
                        player = P1;
                        playerID = Player_1;
                        numberPlayer = 2;
                        cout << "\nPlayer 1 : ";
                        break;
                    }
                    case 2:
                    {
                        player = P2;
                        playerID = Player_2;
                        numberPlayer = 1;
                        cout << "\nPlayer 2 : ";
                        break;
                    }
                }
                while (!Board.PlayerMove(player->move(),playerID));

                cout << "\n" << Board;
                if (Board.Win(playerID))
                {
                    if (numberPlayer == 1)
                        cout << "\nPlayer 2 WIN" << endl;
                    else
                        cout << "\nPlayer 1 WIN" << endl;

                    player->setPlayerWins();
                    break;
                }
            }

            cout << "Player 1 Won : " << P1->getPlayerWins() << " times" << endl;
            cout << "Player 2 Won : " << P2->getPlayerWins() << " times" << endl;

            cout << "\nWant to play again?\n";
            cout << "type <Y> to repeat or <N> to stop : ";

            if (F_repeat())
            {
                Board.ResetField();
                system("cls");
                cout << "\n" << Board << endl;

            }
            else
            {
                Board.ResetField();
                delete P1;
                delete P2;
                break;
            }
        }
    }
    return 0;
}
