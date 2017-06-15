#include <iostream>
#include "fractionStruct.cpp"

using namespace std;

uFraction operator+ (const uFraction& first, const uFraction& second)
{
    uFraction result;
    result.nom = first.nom * second.den + second.nom * first.den;
    result.den = first.den * second.den;
    result.Reduce();
    return result;
}


int main(void)
{
    int readVal;
    uFraction F1;
    uFraction F2 {3,5};
    uFraction F3;
    cout << "\nInsert 1 value of the numerator : ";
    cin >> readVal;
    F1.setNumerator(readVal);
    cout << "Insert 1 value of the denominator : ";
    cin >> readVal;
    F1.setDenominator(readVal);

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

//    F3 = F1 + F2;
//    F1 += F2;
    cout << "\n";
    F1.Reduce();
    F1.printFraction();
    cout << " + ";
    F2.Reduce();
    F2.printFraction();
    cout << " = ";
    F1 += F2;
    F1.Reduce();
    F1.printFraction();
    F3 = F1 + F2;

//    F1.printFraction();
//    cout << endl;
//    F2.printFraction();
    cout << endl;
//    system("pause");
    return 0;
}
