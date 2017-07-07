#ifndef FIELD_H
#define FIELD_H

#include <iostream>

class playerField
{
private:
    size_t Row;
    size_t Col;
    size_t fieldLenght;
    int* Field;
    static size_t countMoves;

public:
    playerField();
    ~playerField();
    int player1ID() const;
    int player2ID() const;
    bool isMove();
    void ResetField();
    bool PlayerMove(int, int);
    bool Win(int);
    friend std::ostream& operator<< (std::ostream&, const playerField&);
};

enum pID {Player_1 = 10, Player_2 = 11};

#endif // FIELD_H
