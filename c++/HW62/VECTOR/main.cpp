#include <iostream>
#include "vector.h"

using namespace std;

template <typename T>
void printVector (const Vector<T>& tmp)
{
    cout << endl;
    cout << "Vector address : " << &tmp << endl;
    cout << "Lenght : ";
    cout << tmp.getLenght() << endl;
    cout << "Elements in vector : ";
    tmp.printVector();
}

int main()
{

//    size_t lenght1;
//    size_t lenght2 = 2;
    Vector<int> V1 (40);
    Vector<int> V3 (70);
    Vector<double> V2 (6);
    Vector<double> V4 (3);
    Vector<int> V10 (5);

    cout << endl;
    cout << "Adress V1 = " << &V1 << endl;
    cout << "Adress V2 = " << &V2 << endl;

    for (size_t i = 0; i < V1.getLenght(); ++i)
        V1.setElement(i,i+10);

    for (size_t i = 0; i < V2.getLenght(); ++i)
        V2.setElement(i,i+20);

    for (size_t i = 0; i < V3.getLenght(); ++i)
        V3.setElement(i,i+30);

    for (size_t i = 0; i < V4.getLenght(); ++i)
        V4.setElement(i,i+40);

    for (size_t i = 0; i < V10.getLenght(); ++i)
        V10.setElement(i,i+100);

    cout << endl;
    cout << "V1 :";
    printVector (V1);

    cout << endl;
    cout << "V2 : ";
    printVector(V2);

    cout << endl;
    cout << "V3 : ";
    printVector(V3);

    cout << endl;
    cout << "V4 : ";
    printVector(V4);

    cout << endl;
    cout << "V10 : ";
    printVector(V10);

    if (V1 == V3)
        cout << "\n V1 == V2";
    else
        cout<< "\n V1 != V3";

    cout << "\nV1[2] : " << V1[2] << endl;
//    cout << "\nV1 = V3" << endl;
//    V1 = V3;
//    cout << "\nV2 = V4" << endl;
//    V2 = V4;

//    cout << endl;
//    cout << "V1 :";
//    printVector (V1);

//    cout << endl;
//    cout << "V2 : ";
//    printVector(V2);

//    cout << endl;
//    cout << "V3 : ";
//    printVector(V3);

//    cout << endl;
//    cout << "V4 : ";
//    printVector(V4);

//    if (V1 == V3)
//        cout << "\n V1 == V2";
//    else
//        cout<< "\n V1 != V3";
//V2.vector;

//    cout << "\nswap Vector V1 with V3 \n";
//    V1.swap(V10);
//    cout << endl;
//    cout << "V1 :";
//    printVector (V1);

//    cout << endl;
//    cout << "V10 : ";
//    printVector(V10);


//    cout << "\nswap Vector V1 with V3 \n";
//    V10.swap(V1);
//    cout << endl;
//    cout << "V1 :";
//    printVector (V1);

//    cout << endl;
//    cout << "V10 : ";
//    printVector(V10);

    cout << endl;
    return 0;
}
