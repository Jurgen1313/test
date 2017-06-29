#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class Matrix
{
    int Row;
    int Col;
    int** matrix;
    static int allObjCount;
    static int currentObjCount;

    public:
        Matrix();
        Matrix(int, int = 1);
        Matrix(const Matrix&);
        ~Matrix();

        void printMatrix() const;
        Matrix& operator+= (const Matrix&);
        Matrix& operator-= (const Matrix&);
//        Matrix& operator*= (const Matrix&);
//        Matrix& operator/= (const Matrix&);

};

Matrix operator+ (Matrix f, const Matrix& s);
Matrix operator- (Matrix f, const Matrix& s);

#endif // MATRIX_H
