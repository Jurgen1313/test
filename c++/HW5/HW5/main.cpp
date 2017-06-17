#include <iostream>
//#include "fractionStruct.cpp"
#include "fraction.h"

using namespace std;

int main(void)
{
    int readVal;
    uFraction F1;
    uFraction F2 {3,5};
    uFraction F3,F4;

    cout << "\nAddress1 = " << &F1;
    cout << "\nAddress2 = " << &F2;
    cout << "\nAddress3 = " << &F3;
    cout << "\nAddress4 = " << &F4;
//    cout << "\nPointer = " << F1;
    cout << "\nInsert 1 value of the numerator : ";
    cin >> readVal;
    F1.setNumerator(readVal);
    cout << "Insert 1 value of the denominator : ";
    cin >> readVal;
    F1.setDenominator(readVal);
    F1.negativeFraction();

    cout << "\nInsert 2 value of the numerator : ";
    cin >> readVal;
    F2.setNumerator(readVal);
    cout << "Insert 2 value of the denominator : ";
    cin >> readVal;
    F2.setDenominator(readVal);

//    cout << "\n" << F1.printFraction() << " + " << F2.printFraction() << " = " << F1 + F2 << endl;
    cout << endl;
    F1.printFraction();
    cout << endl;
    F2.printFraction();
    cout << endl;

    F3 = (F1^2) + F2 + F4;
//    F1 += F2;
    cout << "\n";
    F1.Reduce();
    F1.printFraction();
    cout << " + ";
    F2.Reduce();
    F2.printFraction();
    cout << " + ";
    F4.Reduce();
    F4.printFraction();
    cout << " = ";
//    F1 /= F2;
    F3.Reduce();
    F3.printFraction();


    cout << "\nAddress1 = " << &F1;
    cout << "\nAddress2 = " << &F2;
    cout << "\nAddress3 = " << &F3;
    cout << "\nAddress4 = " << &F4;
    cout << "\n";
    (F1^2).printFraction();
//    F1.Reduce();
//    F3.printFraction();
//    cout << " / ";
// //    F2.Reduce();
//    F2.printFraction();
//    cout << " = ";
// //    F3.Reduce();
//    F3.printFraction();

//    F1.printFraction();
//    cout << endl;
//    F2.printFraction();
    cout << endl;
//    system("pause");
    return 0;
}
