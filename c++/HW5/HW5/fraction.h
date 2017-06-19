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

    uFraction (const int,const int);

    void setNumerator(const int);

    void setDenominator(const int);

    void setFraction (const int,const int);

    int getNumerator() const;

    int getDenominator() const;

    void printFraction() const;

    int gcd(int, int) const;

    void Reduce();

    void negativeFraction();

    uFraction aProgression(const int, const int) const;

    uFraction aProgression(const uFraction&, int) const;

    uFraction& operator+= (const uFraction&);

    uFraction& operator-= (const uFraction&);

    uFraction& operator*= (const uFraction&);

    uFraction& operator/= (const uFraction&);

    uFraction operator+ (const uFraction&) const;

    uFraction operator- (const uFraction&) const;

    uFraction operator* (const uFraction&) const;

    uFraction operator/ (const uFraction&) const;

    uFraction operator+ (const int) const;

    uFraction operator- (const int) const;

    uFraction operator* (const int) const;

    uFraction operator/ (const int) const;

    friend uFraction operator+ (const int, const uFraction&);
    friend uFraction operator- (const int, const uFraction&);
    friend uFraction operator* (const int, const uFraction&);
    friend uFraction operator/ (const int, const uFraction&);

    uFraction operator^ (const int) const;

    uFraction operator^ (const uFraction&) const;

    int operator> (const uFraction&) const;
    int operator< (const uFraction&) const;
    int operator>= (const uFraction&) const;
    int operator<= (const uFraction&) const;

    friend std::ostream& operator<< (std::ostream&, const uFraction&);

};



#endif // FRACTION_H
