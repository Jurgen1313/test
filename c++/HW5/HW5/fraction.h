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

//    uFraction (int nom_, int den_);
    uFraction (int, int);

    void setNumerator(int);

    void setDenominator(int);

    void setFraction (int, int);

    int getNumerator() const;

    int getDenominator() const;

    void printFraction() const;

    int gcd(int, int) const;

    void Reduce();

    void negativeFraction();

    uFraction& operator+= (const uFraction&);

    uFraction& operator-= (const uFraction&);

    uFraction& operator*= (const uFraction&);

    uFraction& operator/= (const uFraction&);

    uFraction operator+ (const uFraction&) const;

    uFraction operator- (const uFraction&) const;

    uFraction operator* (const uFraction&) const;

    uFraction operator/ (const uFraction&) const;

    uFraction operator^ (int) const;
};



#endif // FRACTION_H
