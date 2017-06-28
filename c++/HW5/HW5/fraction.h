#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>

struct uFraction
{
    int nom;
    int den;
//    uFraction *pNext;

    uFraction ();
    uFraction (const int,const int);

    void setNumerator(const int);
    void setDenominator(const int);
    void setFraction (const int,const int);
    int getNumerator() const;
    int getDenominator() const;
    void printFraction() const;
    void Reduce();
    void negativeFraction();

    uFraction& operator+= (const uFraction&);
    uFraction& operator-= (const uFraction&);
    uFraction& operator*= (const uFraction&);
    uFraction& operator/= (const uFraction&);

    int operator> (const uFraction&) const;
    int operator< (const uFraction&) const;
    int operator>= (const uFraction&) const;
    int operator<= (const uFraction&) const;

    friend std::ostream& operator<< (std::ostream&, const uFraction&);
};

    uFraction operator+ (uFraction, const uFraction&);
    uFraction operator- (uFraction, const uFraction&);
    uFraction operator* (uFraction, const uFraction&);
    uFraction operator/ (uFraction, const uFraction&);
    uFraction operator+ (const int number, const uFraction& f);
    uFraction operator- (const int number, const uFraction& f);
    uFraction operator* (const int number, const uFraction& f);
    uFraction operator/ (const int number, const uFraction& f);
    uFraction operator+ (const uFraction& f, const int number);
    uFraction operator- (const uFraction& f, const int number);
    uFraction operator* (const uFraction& f, const int number);
    uFraction operator/ (const uFraction& f, const int number);
    int gcd(int, int);

#endif // FRACTION_H
