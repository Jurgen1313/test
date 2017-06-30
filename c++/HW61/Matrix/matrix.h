#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <exception>

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
        void shortPrintMatrix() const;
        Matrix& operator+= (const Matrix&);
        Matrix& operator-= (const Matrix&);
        Matrix& operator= (const Matrix&);
//        Matrix& operator*= (const Matrix&);

        friend Matrix operator* (Matrix, const int);

};

Matrix operator+ (Matrix, const Matrix&);
Matrix operator- (Matrix, const Matrix&);
Matrix operator* (const int, Matrix);

#endif // MATRIX_H
