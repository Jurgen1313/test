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

    cout << endl << "F1 = ";
    F1.printFraction();
    cout << endl << "F2 = ";
    F2.printFraction();
    cout << endl;

    if (F1 > F2)
        cout << F1 << " > " << F2 << endl;
    else if (F1 < F2)
        cout << F1 << " < " << F2 << endl;
    else
        cout << F1 << " = " << F2 << endl;

    int n = 2;
    F3 = n + F1;
    cout << "F3 = n + F1 :: " << n << " + " << F1 << " = " << F3 << endl;
    F3 = F1 + n;
    cout << "F3 = F1 + n :: " << F1 << " + " << n << " = " << F3 << endl;
    F3 = n - F1;
    cout << "F3 = n - F1 :: " << n << " - " << F1 << " = " << F3 << endl;
    F3 = F1 - n;
    cout << "F3 = F1 - n :: " << F1 << " - " << n << " = " << F3 << endl;
    F3 = n / F1;
    cout << "F3 = n / F1 :: " << n << " / " << F1 << " = " << F3 << endl;
    F3 = F1 / n;
    cout << "F3 = F1 / n :: " << F1 << " / " << n << " = " << F3 << endl;
    F3 = n * F1;
    cout << "F3 = n * F1 :: " << n << " * " << F1 << " = " << F3 << endl;
    F3 = F1 * n;
    cout << "F3 = F1 * n :: " << F1 << " * " << n << " = " << F3 << endl;



//    F3 = F1 + F2 + F4;
//    cout << "\n";
//    F1.Reduce();
//    F1.printFraction();
//    cout << " + ";
//    F2.Reduce();
//    F2.printFraction();
//    cout << " + ";
//    F4.Reduce();
//    F4.printFraction();
//    cout << " = ";
//    F3.Reduce();
//    F3.printFraction();

//    cout << "\n";
//    (F1^2).printFraction();
//    cout << endl;
//    int n = 5;
//    int d = 10;
//    F3 = ((F1 * 2)+(n-1)*d)*n/2;
//    F3.printFraction();
    cout << endl;

//    system("pause");
    return 0;
}
