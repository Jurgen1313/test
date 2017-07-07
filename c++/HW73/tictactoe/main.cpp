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
    Human H1;
    Human H2;
    Bot_L1 B1;
    //    size_t PlayerNumber = 1;
    //    size_t Move = 0;
    //    int playerID;

    Player *P1 = 0;
    Player *P2 = 0;

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
            for (;;)
            {

                // Player 1 Move
                if (!Board.isMove())
                {
                    cout << "\nDRAW GAME\n";
                    break;
                }
                while (!Board.PlayerMove(P1->move(),Player_1));
                cout << "\n" << Board;
                if (Board.Win(Player_1))
                {
                    cout << "\nPlayer 1 WIN" << endl;
                    P1->setPlayerWins();
                    break;
                }

                // Player 2 Move
                if (!Board.isMove())
                {
                    cout << "\nDRAW GAME\n";
                    break;
                }
                while (!Board.PlayerMove(P2->move(),Player_2));
                cout << "\n" << Board;
                if (Board.Win(Player_2))
                {
                    cout << "\nPlayer 2 WIN" << endl;
                    P2->setPlayerWins();
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
                delete P1;
                delete P2;
                break;
            }
        }
    }

    return 0;
}
