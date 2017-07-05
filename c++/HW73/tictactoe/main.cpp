#include <iostream>
#include "field.h"
#include "player.h"

using namespace std;

int main()
{
    playerField Board;
    cout << Board;

    size_t i = 0;

        while( Board.isMove())
        {
            int cell;
            cout << "Type cell number : ";
            cin >> i;
            Board.PlayerMove(i-1);
            cout << "\n" << Board;
        }
        if (Board.getPlayerNumber() == 0)
        {
            cout << "\nDRAW GAME";
        }
        else
        {
            cout << "\nWin Player " << Board.getPlayerNumber();
        }
    return 0;
}
