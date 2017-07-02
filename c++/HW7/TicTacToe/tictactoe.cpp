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
//    int Winner = 0;
    //Check horizontal
    for (size_t i = 0; i < Col; ++i)
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
//            Winner = 1;
            return 1;
        }
        if (sumX == 3)
        {
            std::cout << "Win Player 2" << std::endl;
            ++Player2Wins_;
//            Winner = 1;
            return 1;
        }
    }

    //Check vertical
    for (size_t i = 0; i < Col; ++i)
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
//            Winner = 1;
            return 1;
        }
        if (sumX == 3)
        {
            std::cout << "Win Player 2" << std::endl;
            ++Player2Wins_;
//            Winner = 1;
            return 1;
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
//            Winner = 1;
            return 1;
        }
        if (sumX == 3)
        {
            std::cout << "Win Player 2" << std::endl;
            ++Player2Wins_;
//            Winner = 1;
            return 1;
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
//            Winner = 1;
            return 1;
        }
        if (sumX == 3)
        {
            std::cout << "Win Player 2" << std::endl;
            ++Player2Wins_;
//            Winner = 1;
            return 1;
        }
    }
//    if (Winner)
//    {
//        return 1;
//    }
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

// AI
// AI
// AI
// AI
// AI


// This is the evaluation function as discussed
// in the previous article ( http://goo.gl/sJgv68 )
int evaluate(int* b)
{
    size_t n =3;
    // Checking for Rows for X or O victory.
    for (size_t i = 0; i < n; ++i)
    {
//        size_t j = 0;
            if (b[i*3+0]==b[i*3+1]&& b[i*3+1]==b[i*3+2])
            {
                if (b[i*3]== 10)
                    return +10;
                else if (b[i*3]== 11)
                    return -10;
        }

    }
//    for (int row = 0; row<3; row++)
//    {
//        if (b[row][0]==b[row][1] &&
//            b[row][1]==b[row][2])
//        {
//            if (b[row][0]== 10)
//                return +10;
//            else if (b[row][0]== 11)
//                return -10;
//        }
//    }



    // Checking for Columns for X or O victory.
    for (size_t i = 0; i < n; ++i)
    {
            if (b[i]==b[i+3]&& b[i+3]==b[i+3*2])
            {
                if (b[i]== 10)
                    return +10;
                else if (b[i]== 11)
                    return -10;
        }

    }
//    for (int col = 0; col<3; col++)
//    {
//        if (b[0][col]==b[1][col] &&
//            b[1][col]==b[2][col])
//        {
//            if (b[0][col]== 10)
//                return +10;

//            else if (b[0][col]== 11)
//                return -10;
//        }
//    }


    // Checking for Diagonals for X or O victory.
    if (b[0]==b[4] && b[4]==b[8])
    {
        if (b[0] == 10)
            return +10;
        else if (b[0] == 11)
            return -10;
    }
//    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
//    {
//        if (b[0][0] == 10)
//            return +10;
//        else if (b[0][0] == 11)
//            return -10;
//    }

    if (b[2]==b[4] && b[4]==b[6])
    {
        if (b[2] == 10)
            return +10;
        else if (b[2] == 11)
            return -10;
    }
//    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
//    {
//        if (b[0][2] == 10)
//            return +10;
//        else if (b[0][2] == 11)
//            return -10;
//    }

    // Else if none of them have won then return 0
    return 0;
}

// This is the minimax function. It considers all
// the possible ways the game can go and returns
// the value of the board
int minimax(int* board, int depth, bool isMax)
{
    int score = evaluate(board);

    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == 10)
        return score;

    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -10)
        return score;

    // If there are no more moves and no winner then
    // it is a tie
//    if (isMovesLeft(board)==false)
//        return 0;

    // If this maximizer's move
    if (isMax)
    {
        int best = -1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
//                if (board[i][j] != 10 || board[i][j] != 11)
                if (board[j+3*i] != 10 || board[j+3*i] != 11)
                {
                    // Make the move
                    board[j+3*i] = 10;

                    // Call minimax recursively and choose
                    // the maximum value
                    best = std::max( best, minimax(board, depth+1, !isMax) );

                    // Undo the move
                    board[j+3*i] = j+3*i;
                }
            }
        }
        return best;
    }

    // If this minimizer's move
    else
    {
        int best = 1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
//                if (board[i][j]=='_')
                if (board[j+3*i] != 10 || board[j+3*i] != 11)
                {
                    // Make the move
                    board[j+3*i] = 11;

                    // Call minimax recursively and choose
                    // the minimum value
                    best = std::min(best,minimax(board, depth+1, !isMax));

                    // Undo the move
                    board[j+3*i] = j+3*i;
                }
            }
        }
        return best;
    }
}

// This will return the best possible move for the player
int findBestMove(int* board)
{
    int bestVal = -1000;

    // Traverse all cells, evalutae minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            // Check if celll is empty
            if (board[j+3*i] != 10 || board[j+3*i] != 11)
            {
                // Make the move
                board[j+3*i] = 10;

                // compute evaluation function for this
                // move.
                int moveVal = minimax(board, 0, false);

                // Undo the move
                board[j+3*i] = j+3*i;

                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal > bestVal)
                {
                    bestVal = moveVal;
                }
            }
        }
    }

//    printf("The value of the best Move is : %d\n\n",
//            bestVal);

    return bestVal;
}
