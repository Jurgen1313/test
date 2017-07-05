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
        int PlayerNumber;
        static size_t countMoves;

        bool Win();


    public:
        playerField();
        ~playerField();
        int getPlayerNumber() const;

        bool isMove();
        void ResetField();
        void PlayerMove(int);
        friend std::ostream& operator<< (std::ostream&, const playerField&);

};

//size_t countMoves = 0;
#endif // FIELD_H
