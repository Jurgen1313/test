#include <iostream>
#include "player.h"

using namespace std;

void ChoosePlayer(int& P)
{
    char userChoise;
    cout << "\nChoose first player";
    cout << "\nType <H>uman or <B>ot : ";
    bool input_char = true;

    do
    {
        std::cin >> userChoise;
        switch (userChoise)
        {
            case 'H':
            case 'h':
            {
                input_char = false;
                P = 1;
                break;
            }
            case 'B':
            case 'b':
            {
                input_char = false;
                P = 0;
                break;
            }
        }

        if (std::cin.get() != '\n')
        {
            while (std::cin.get() != '\n');
            input_char = true;
            std::cout << "Make correct choise : ";
        }
    } while (input_char);
}

int main()
{
    char userChoise;
    int Player1Choise = 0;
    int Player2Choise = 0;

    const int Row = 3;
    const int Col = 3;
    const int lenght = Row * Col;

    int time_val = time(NULL);
    srand(time_val);

    int* Field = new int [lenght];// {1,2,3,4,5,6,7,8,9};

    for (;;)
    {
        EmptyField(Field, lenght);
        printField(Field, Row, Col);
        cout << "\n\tWelcome to Tic Tac Toe game";
        cout << "\n\tStart the game";
        cout << "\n\tType <Y>es to start or <N>o to quit";
        cout << "\nMake your choise : ";
        userChoise = F_repeat();
        if (!userChoise)
        {
            delete [] Field;
            return 0;
        }
        else
        {
            ChoosePlayer(Player1Choise);
            ChoosePlayer(Player2Choise);
            Player Player1 (Player1Choise, Field);
            Player Player2 (Player2Choise, Field);
            system("cls");
            printField(Field, Row, Col);

            for (;;)
            {
                bool Win = false;
                do
                {
                    Win = Win || Player1.Move();
                    printField(Field, Row, Col);

                    if (!Win)
                    {
                        Win = Win || Player2.Move();
                        printField(Field, Row, Col);
                    }

                }
                while (!Win);

                cout << "Player 1 made : ";
                Player1.printPlayerMoves();
                cout << endl;
                cout << "Player 2 made : ";
                Player2.printPlayerMoves();
                cout << endl;

                cout << "Player 1 Won : " << Player1.getPlayerWins() << " times" << endl;
                cout << "Player 2 Won : " << Player2.getPlayerWins() << " times" << endl;

                cout << "\nWant to play again?\n";
                cout << "type <Y> to repeat or <N> to stop : ";
                userChoise = F_repeat();
                system("cls");
                if (userChoise)
                {
                    EmptyField(Field, lenght);
                    printField(Field, Row, Col);
                    cout << endl;
                }
                else
                    break;
            }
        }
    }
}
