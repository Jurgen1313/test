//#include "fraction.h"
#include <iostream>


struct uFraction
{
    int nom;
    int den;

//    uFraction ()
//    {
//        nom = 1;
//        den = 1;
//    }
    uFraction (int nom_ = 1, int den_ = 1)
    {
        nom = nom_;
        den = den_;
    }
    void setNumerator(int setValue )
    {
        nom = setValue;
    }
    void setDenominator(int setValue)
    {
        den = setValue;
    }
    void setFraction (int setNom, int setDen)
    {
        nom = setNom;
        den = setDen;
        Reduce();
    }
    int getNumerator()
    {
        return nom;
    }
    int getDenominator()
    {
        return den;
    }
    void printFraction()
    {
        std::cout << nom << "/" << den;
    }
    int gcd(int a, int b)
    {
       if (b == 0) return a;
       return gcd(b, a % b);
    }
    void Reduce()
    {
        int gcdVal = gcd(nom, den);
        nom /= gcdVal;
        den /= gcdVal;
    }
    uFraction operator+= (const uFraction& first)
    {
        nom = first.nom * den + nom * first.den;
        den = first.den * den;
        Reduce();
    }

    uFraction operator-= (const uFraction& first)
    {
        nom = first.nom * den - nom * first.den;
        den = first.den * den;
        Reduce();
    }

    uFraction operator*= (const uFraction& first)
    {
        nom = first.nom * nom;
        den = first.den * den;
        Reduce();
    }

    uFraction operator/= (const uFraction& first)
    {
        nom = first.nom * den;
        den = first.den * nom;
        Reduce();
    }

};

