#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    int time_val = time(NULL);
    srand(time_val);

    Matrix m1;
    Matrix m2;

    Matrix m3 = {4,3};
    Matrix m4 {5};
    Matrix m5 {-1};
    Matrix m6 {5,6};
    Matrix m7 {4,3};
    Matrix m8 {4,3};


    std::cout << "\nm3+=m7 :" << std::endl;
    m3 += m7;
    std::cout << "\nm3-=m7 :" << std::endl;
    m3 -= m7;
    std::cout << "\nm8=m3+m7 :" << std::endl;
    m8 = m3 + m7;
    std::cout << "\nm3 :" << std::endl;
    m3.printMatrix();
    std::cout << "\nm8=m3-m7 :" << std::endl;
    m8 = m3 - m7;

    return 0;
}
