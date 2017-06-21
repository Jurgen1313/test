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

    cout << "Compare F1 and F2 " << endl;
    if (F1 > F2)
        cout << F1 << " > " << F2 << endl;
    else if (F1 < F2)
        cout << F1 << " < " << F2 << endl;
    else
        cout << F1 << " = " << F2 << endl;

    cout << "Compare F2 and F1 " << endl;
    if (F2 > F1)
        cout << F2 << " > " << F1 << endl;
    else if (F2 < F1)
        cout << F2 << " < " << F1 << endl;
    else
        cout << F2 << " = " << F1 << endl;

    int n = 2;
    F3 = n + F1;
    cout << "F3  :: " << n << " + " << F1 << " = " << F3 << endl;
    F3 = F1 + n;
    cout << "F3 :: " << F1 << " + " << n << " = " << F3 << endl;
    F3 = n - F1;
    cout << "F3 :: " << n << " - " << F1 << " = " << F3 << endl;
    F3 = F1 - n;
    cout << "F3 :: " << F1 << " - " << n << " = " << F3 << endl;
    F3 = n / F1;
    cout << "F3 :: " << n << " / " << F1 << " = " << F3 << endl;
    F3 = F1 / n;
    cout << "F3 :: " << F1 << " / " << n << " = " << F3 << endl;
    F3 = n * F1;
    cout << "F3 :: " << n << " * " << F1 << " = " << F3 << endl;
    F3 = F1 * n;
    cout << "F3 :: " << F1 << " * " << n << " = " << F3 << endl;

    n = -2;
    F3 = n + F1;
    cout << "F3  :: " << n << " + " << F1 << " = " << F3 << endl;
    F3 = F1 + n;
    cout << "F3 :: " << F1 << " + " << n << " = " << F3 << endl;
    F3 = n - F1;
    cout << "F3 :: " << n << " - " << F1 << " = " << F3 << endl;
    F3 = F1 - n;
    cout << "F3 :: " << F1 << " - " << n << " = " << F3 << endl;
    F3 = n / F1;
    cout << "F3 :: " << n << " / " << F1 << " = " << F3 << endl;
    F3 = F1 / n;
    cout << "F3 :: " << F1 << " / " << n << " = " << F3 << endl;
    F3 = n * F1;
    cout << "F3 :: " << n << " * " << F1 << " = " << F3 << endl;
    F3 = F1 * n;
    cout << "F3 :: " << F1 << " * " << n << " = " << F3 << endl;

    F3 = F1 + F2;
    cout << "F3 :: " << F1 << " + " << F2 << " = " << F3 << endl;
    F3 = F2 + F1;
    cout << "F3 :: " << F2 << " + " << F1 << " = " << F3 << endl;
    F3 = F1 - F2;
    cout << "F3 :: " << F1 << " - " << F2 << " = " << F3 << endl;
    F3 = F2 - F1;
    cout << "F3 :: " << F2 << " - " << F1 << " = " << F3 << endl;
    F3 = F1 * F2;
    cout << "F3 :: " << F1 << " * " << F2 << " = " << F3 << endl;
    F3 = F2 * F1;
    cout << "F3 :: " << F2 << " * " << F1 << " = " << F3 << endl;
    cout << "F1+= :: " << F1;
    F1 += F2;
    cout << " + " << F2 << " = " << F1 << endl;
    cout << "F1-= :: " << F1;
    F1 -= F2;
    cout << " - " << F2 << " = " << F1 << endl;
    cout << "F1*= :: " << F1;
    F1 *= F2;
    cout << " * " << F2 << " = " << F1 << endl;
    cout << "F1/= :: " << F1;
    F1 /= F2;
    cout << " / " << F2 << " = " << F1 << endl;
    n = 10;
    int d = 3;
    F3 = n/2*((2 * F1)+(n-1)*d);
    cout << " Arithmetic progression starts from " << F1 << " with " << n << " elements and step " << d << " is equal : "<< F3 << endl;
    cout << endl;

//    system("pause");
    return 0;
}
