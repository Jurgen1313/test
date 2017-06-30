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
    Matrix m5 {1};
    Matrix m6 {5,6};
    Matrix m7 {3,4};
    Matrix m8 {4,3};

    std::cout << "\nm3 :" << std::endl;
    m3.shortPrintMatrix();
    std::cout << "\nm7 :" << std::endl;
    m7.shortPrintMatrix();
    std::cout << "\nm8=m3*m7 :" << std::endl;
    m8 = m3 * m7;
    m8.shortPrintMatrix();
//    std::cout << "\nm3+=m7 :" << std::endl;
//    m3 += m7;
//    std::cout << "\nm3-=m7 :" << std::endl;
//    m3 -= m7;
// //    std::cout << "\nm8=m3+m7 :" << std::endl;
// //    m8 = m3 + m7;
//    std::cout << "\nm3 :" << std::endl;
//    m3.shortPrintMatrix();
//    std::cout << "\nm7 :" << std::endl;
//    m7.shortPrintMatrix();
//    std::cout << "\nm8=m3+m7 :" << std::endl;
//    m8 = m3 + m7;
//    std::cout << "\nm8 :" << std::endl;
//    m8.shortPrintMatrix();
//    std::cout << "\nm3 :" << std::endl;
//    m3.shortPrintMatrix();
//    std::cout << "\nm7 :" << std::endl;
//    m7.shortPrintMatrix();
//    std::cout << "\nm8=m3-m7 :" << std::endl;
//    m8 = m3 - m7;
//    std::cout << "\nm8 :" << std::endl;
//    m8.shortPrintMatrix();

//    std::cout << "\nm3 :" << std::endl;
//    m3.shortPrintMatrix();
//    std::cout << "\nm7 :" << std::endl;
//    m7.shortPrintMatrix();
//    std::cout << "\nm3=m7 :" << std::endl;
//    m3 = m7;
//    std::cout << "\nm3 :" << std::endl;
//    m3.shortPrintMatrix();

//    m8 = m3 * 2;
//    m7 = 2 * m3;
//    std::cout << "\nm8=m3*2 :" << std::endl;
//    m8.shortPrintMatrix();
//    std::cout << "\nm7=2*m3 :" << std::endl;
//    m7.shortPrintMatrix();

    return 0;
}
