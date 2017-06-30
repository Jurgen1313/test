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
    for (size_t i = 0; i < Row; ++i)
    {
        matrix[i] = new int [Col] {0};
//        *(matrix + i) = new int [Col] {0};
        // Just for testing
        for (size_t j= 0; j < Col; ++j)
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

Matrix::Matrix(size_t Col_, size_t Row_): Row(Row_), Col(Col_)
{
    matrix = new int* [Row];
    for (size_t i = 0; i < Row; ++i)
    {
        matrix[i] = new int [Col] {0};
        // Just for testing
        for (size_t j= 0; j < Col; ++j)
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
    for (size_t i = 0; i < Row; ++i)
    {
        matrix[i] = new int [Col] {0};
        // Just for testing
        for (size_t j= 0; j < Col; ++j)
        {
            matrix[i][j] = copy.matrix[i][j];
        }
        // Just for testing ----- END
    }
//    std::cout << "COPY" << std::endl;
}


Matrix::~Matrix()
{
    for (size_t i = 0; i < Row; ++i)
        delete [] matrix[i];
    delete [] matrix;
    --currentObjCount;

    // Just for testing
//    std::cout << " deleted obj" << std::endl;
//    std::cout << " currentObjCount = " << currentObjCount << std::endl;
//    std::cout << " allObjCount = " << allObjCount << std::endl;
    // Just for testing ----- END
}

size_t Matrix::getRow() const
{
    return Row;
}
size_t Matrix::getCol() const
{
    return Col;
}

Matrix& Matrix::operator+= (const Matrix& s)
{
    if ((Row == s.Row)&&(Col == s.Col))
    {
        for (size_t i = 0; i < Row; ++i)
            for (size_t j = 0; j < Col; ++j)
                matrix[i][j] += s.matrix[i][j];
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
        for (size_t i = 0; i < Row; ++i)
            for (size_t j = 0; j < Col; ++j)
                matrix[i][j] -= s.matrix[i][j];
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
    for (size_t i = 0; i < Row; ++i)
    {
        for (size_t j = 0; j < Col; ++j)
            std::cout << "matrix[" << i << "][" << j << "] = " << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Matrix::shortPrintMatrix() const
{
    std::cout << std::endl;
    for (size_t i = 0; i < Row; ++i)
    {
        for (size_t j = 0; j < Col; ++j)
            std::cout << matrix[i][j] << " ";
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

    for (size_t i = 0; i < Row; ++i)
        delete [] matrix[i];
    delete [] matrix;

    Row = rv.Row;
    Col = rv.Col;
    matrix = new int* [Row];
    for (size_t i = 0; i < Row; ++i)
    {
        *(matrix + i) = new int [Col] {0};
        for (size_t j = 0; j < Col; ++j)
            matrix[i][j] = rv.matrix[i][j];
    }
    return *this;
}

Matrix operator* (Matrix lv, const int number)
{
    for (size_t i = 0; i < lv.Row; ++i)
        for (size_t j = 0; j < lv.Col; ++j)
            lv.matrix[i][j] *= number;
    return lv;
}

Matrix operator* (const int number, Matrix lv)
{
    return lv * number;
}


Matrix operator* (const Matrix& f, const Matrix& s)
{
    if ((f.Row == s.Col)&&(f.Col == s.Row))
    {
        Matrix tmp {s.Col, f.Row};
        for (size_t i = 0; i < f.Row; ++i)
            for (size_t j = 0; j < s.Col; ++j)
            {
                int sum = 0;
                for (size_t k = 0; k < f.Col; ++k)
//                    tmp.matrix[i][j] = f.matrix[i][k] * s.matrix[k][j];
                    sum += f.matrix[i][k] * s.matrix[k][j];
                tmp.matrix[i][j] = sum;
            }
        return tmp;
    }
    else
    {
        std::cout << "You can't MUL this Matrixs!!!" << std::endl;
        exit(1);
    }
}

std::ostream& operator<< (std::ostream& os, const Matrix& tmp)
{
    for (size_t i = 0; i < tmp.Row; ++i)
    {
        for(size_t j = 0; j < tmp.Col; ++j)
            os << " " << tmp.matrix[i][j];
        os << std::endl;
    }
    return os;
}

std::istream& operator>> (std::istream& is, Matrix& tmp)
{
    int value;
    size_t i = 0; //Row
    size_t j = 0; //Col

    while (i < tmp.Row)
    {
        std::cout << "matrix [" << i << "][" << j << "] = ";
        if( is >> value )
        {
            tmp.matrix[i][j] = value;
            ++j;
            if ( j == tmp.Col )
            {
                j = 0;
                ++i;
            }
        }
    }
    return is;
}

Matrix& Matrix::operator*= (const Matrix& r)
{
    Matrix tmp {r.Col, Row};
    tmp = *this * r;
    *this = tmp;
    return *this;
}




