#include "matrix.h"
#include <new>

int Matrix::allObjCount = 0;
int Matrix::currentObjCount = 0;


Matrix::Matrix(): Row (1), Col(3)
{
    try
    {
        matrix = new int* [Row];
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "I can't allocate mempry for matrix : " << std::endl;
    }
    for (int i = 0; i < Row; ++i)
    {
//        matrix[i] = new int [Col] {0};
        *(matrix + i) = new int [Col] {0};
        // Just for testing
        for (int j= 0; j < Col; ++j)
        {
            int rand_number;
            rand_number = rand() % 11;
            std::cout << (matrix[i][j] = rand_number) << "  ";
        }
        // Just for testing ----- END
    }

    allObjCount++;
    currentObjCount++;
}

Matrix::Matrix(int Col_, int Row_): Row(Row_), Col(Col_)
{
    matrix = new int* [Row];
    for (int i = 0; i < Row; ++i)
    {
        matrix[i] = new int [Col] {0};
        // Just for testing
        for (int j= 0; j < Col; ++j)
        {
            int rand_number;
            rand_number = rand() % 11;
            matrix[i][j] = rand_number;
        }
        // Just for testing ----- END
    }

    allObjCount++;
    currentObjCount++;
}

Matrix::Matrix(const Matrix& copy)
{
    allObjCount++;
    currentObjCount++;
    Row = copy.Row;
    Col = copy.Col;
    matrix = new int* [Row];
    for (int i = 0; i < Row; ++i)
    {
        matrix[i] = new int [Col] {0};
        // Just for testing
        for (int j= 0; j < Col; ++j)
        {
            matrix[i][j] = copy.matrix[i][j];
        }
        // Just for testing ----- END
    }
    std::cout << "COPY" << std::endl;
}


Matrix::~Matrix()
{
    for (int i = 0; i < Row; ++i)
        delete [] matrix[i];
    delete [] matrix;
    --currentObjCount;

    // Just for testing
    std::cout << " deleted obj" << std::endl;
//    std::cout << " currentObjCount = " << currentObjCount << std::endl;
//    std::cout << " allObjCount = " << allObjCount << std::endl;
    // Just for testing ----- END
}

Matrix& Matrix::operator+= (const Matrix& s)
{
    if ((Row == s.Row)&&(Col == s.Col))
    {
        for (int i = 0; i < Row; ++i)
        {
            for (int j = 0; j < Col; ++j)
            {
                matrix[i][j] += s.matrix[i][j];
            }
        }
        return *this;
    }
    else
    {
        std::cout << "You can't add this Matrixs!!!" << std::endl;
        exit(1);
    }
}

Matrix& Matrix::operator-= (const Matrix& s)
{
    if ((Row == s.Row)&&(Col == s.Col))
    {
        for (int i = 0; i < Row; ++i)
        {
            for (int j = 0; j < Col; ++j)
            {
                matrix[i][j] -= s.matrix[i][j];
            }
        }
        return *this;
    }
    else
    {
        std::cout << "You can't sub this Matrixs!!!" << std::endl;
        exit(1);
    }
}


void Matrix::printMatrix() const
{
    std::cout << std::endl;
    for (int i = 0; i < Row; ++i)
    {
        for (int j = 0; j < Col; ++j)
        {
            std::cout << "matrix[" << i << "][" << j << "] = " << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Matrix::shortPrintMatrix() const
{
    std::cout << std::endl;
    for (int i = 0; i < Row; ++i)
    {
        for (int j = 0; j < Col; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

Matrix operator+ (Matrix f, const Matrix& s)
{
    return f+=s;
}

Matrix operator- (Matrix f, const Matrix& s)
{
    return f-=s;
}

Matrix& Matrix::operator= (const Matrix& rv)
{
    if (this == &rv)
        return *this;

    for (int i = 0; i < Row; ++i)
        delete [] matrix[i];
    delete [] matrix;

    Row = rv.Row;
    Col = rv.Col;
    matrix = new int* [Row];
    for (int i = 0; i < Row; ++i)
    {
        *(matrix + i) = new int [Col] {0};
        for (int j = 0; j < Col; ++j)
            matrix[i][j] = rv.matrix[i][j];
    }
    return *this;
}

Matrix operator* (Matrix lv, const int number)
{
    for (int i = 0; i < lv.Row; ++i)
        for (int j = 0; j < lv.Col; ++j)
            lv.matrix[i][j] *= number;
    return lv;
}

Matrix operator* (const int number, Matrix lv)
{
    return lv * number;
}


//Matrix& Matrix::operator*= (const Matrix& s)
//{
//    Matrix tmp {Row, Col};
//    if ((Row == s.Row)&&(Col == s.Col))
//    {
//        for (int i = 0; i < Row; ++i)
//        {
//            for (int j = 0; j < Col; ++j)
//            {
//               tmp.matrix[i][j] = matrix[i][j] -= s.matrix[i][j];
//            }
//        }
//        return *this;
//    }
//    else
//    {
//        std::cout << "You can't MUL this Matrixs!!!" << std::endl;
//        exit(1);
//    }
//}




