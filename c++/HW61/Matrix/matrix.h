#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <exception>

class Matrix
{
    size_t Row;
    size_t Col;
    int** matrix;
    static int allObjCount;
    static int currentObjCount;

    public:
        Matrix();
        Matrix(size_t, size_t = 1);
        Matrix(const Matrix&);
        ~Matrix();

        size_t getRow() const;
        size_t getCol() const;
        size_t setRow();
        size_t setCol();
//        void setMatrix();

        void printMatrix() const;
        void shortPrintMatrix() const;

        Matrix& operator+= (const Matrix&);
        Matrix& operator-= (const Matrix&);
        Matrix& operator= (const Matrix&);
        Matrix& operator*= (const Matrix&);

        friend std::ostream& operator<< (std::ostream&, const Matrix&);
        friend std::istream& operator>> (std::istream&, Matrix&);
        friend Matrix operator* (Matrix, const int);
        friend Matrix operator* (const Matrix& f, const Matrix& s);

};

Matrix operator+ (Matrix, const Matrix&);
Matrix operator- (Matrix, const Matrix&);
Matrix operator* (const int, Matrix);

#endif // MATRIX_H
