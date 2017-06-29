#include "matrix.h"

int Matrix::allObjCount = 0;
int Matrix::currentObjCount = 0;


Matrix::Matrix(): Row (1), Col(3)
{
    matrix = new int* [Row];
//    if (!matrix)
//    {
//        std::cout << "ERROR!!! I can't allocate memory for NEW class!!" << std::endl;
//    }
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

    // Just for testing
    std::cout << "\nRow = " << Row << " Col = " << Col << std::endl;
    std::cout << "classAllValue = " << allObjCount << std::endl;
    std::cout << "classCurrentNumber = " << currentObjCount << std::endl << std:: endl;
    // Just for testing ----- END
}

Matrix::Matrix(int Col_, int Row_): Row(abs(Row_)), Col(abs(Col_))
{
    matrix = new int* [Row];
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
        std::cout << std::endl;
        // Just for testing ----- END
    }

    allObjCount++;
    currentObjCount++;
    // Just for testing
    std::cout << "\nRow = " << Row << " Col = " << Col << std::endl;
    std::cout << "classAllValue = " << allObjCount << std::endl;
    std::cout << "classCurrentNumber = " << currentObjCount << std::endl;
    // Just for testing ----- END
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
//        matrix[i] = new int [Col] {0};
        *(matrix + i) = new int [Col] {0};
        // Just for testing
        for (int j= 0; j < Col; ++j)
        {
            matrix[i][j] = copy.matrix[i][j];
            std::cout << matrix[i][j]<< "  ";
        }
        std::cout << std::endl;
        // Just for testing ----- END
    }
}


Matrix::~Matrix()
{
    for (int i = 0; i < Row; ++i)
        delete [] matrix[i];
    delete [] matrix;
    --currentObjCount;

    // Just for testing
    std::cout << " deleted obj" << std::endl;
    std::cout << " currentObjCount = " << currentObjCount << std::endl;
    std::cout << " allObjCount = " << allObjCount << std::endl;
    // Just for testing ----- END
}

Matrix& Matrix::operator+= (const Matrix& s)
{
    this->printMatrix();
    s.printMatrix();

    if ((Row == s.Row)&&(Col == s.Col))
    {
        for (int i = 0; i < Row; ++i)
        {
            for (int j = 0; j < Col; ++j)
            {
                matrix[i][j] += s.matrix[i][j];
                std::cout << "matrix[" << i << "][" << j << "] = " << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
        return *this;
    }
    else
    {
        std::cout << "You can't add this Matrix!!!" << std::endl;
        exit(1);
    }
}

Matrix& Matrix::operator-= (const Matrix& s)
{
    this->printMatrix();
    s.printMatrix();

    if ((Row == s.Row)&&(Col == s.Col))
    {
        for (int i = 0; i < Row; ++i)
        {
            for (int j = 0; j < Col; ++j)
            {
                matrix[i][j] -= s.matrix[i][j];
                std::cout << "matrix[" << i << "][" << j << "] = " << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
        return *this;
    }
    else
    {
        std::cout << "You can't sub this Matrix!!!" << std::endl;
        exit(1);
    }
}


void Matrix::printMatrix() const
{
    std::cout << std::endl;
    // Print first Matrix
    for (int i = 0; i < Row; ++i)
    {
        for (int j = 0; j < Col; ++j)
        {
            std::cout << "matrix[" << i << "][" << j << "] = " << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    //END of printing
}

Matrix operator+ (Matrix f, const Matrix& s)
{
//    f+=s;
    return f+=s;
}

Matrix operator- (Matrix f, const Matrix& s)
{
    return f-=s;
}



