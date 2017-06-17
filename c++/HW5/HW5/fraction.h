#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>

struct uFraction
{
    int nom;
    int den;
    uFraction *pNext;

    uFraction ();

    uFraction (int nom_, int den_);

    void setNumerator(int setValue );

    void setDenominator(int setValue);

    void setFraction (int setNom, int setDen);

    int getNumerator() const;

    int getDenominator() const;

    void printFraction() const;

    int gcd(int a, int b) const;

    void Reduce();

    uFraction& operator+= (const uFraction& first);

    uFraction& operator-= (const uFraction& first);

    uFraction& operator*= (const uFraction& first);

    uFraction& operator/= (const uFraction& first);

    uFraction operator+ (const uFraction& second) const;

    uFraction operator- (const uFraction& second) const;

    uFraction operator* (const uFraction& second) const;

    uFraction operator/ (const uFraction& second) const;
};



#endif // FRACTION_H
