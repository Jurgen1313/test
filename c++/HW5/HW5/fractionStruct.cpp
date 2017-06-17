#include "fraction.h"
//#include <iostream>
//#include <cmath>

uFraction::uFraction ()
{
    nom = 1;
    den = 1;
}

uFraction::uFraction (int nom_, int den_)
{
    nom = nom_;
    den = den_;
}
void uFraction::setNumerator(int setValue )
{
    nom = setValue;
}
void uFraction::setDenominator(int setValue)
{
    den = setValue;
}
void uFraction::setFraction (int setNom, int setDen)
{
    nom = setNom;
    den = setDen;
    Reduce();
}
int uFraction::getNumerator() const
{
    return nom;
}
int uFraction::getDenominator() const
{
    return den;
}
void uFraction::printFraction() const
{
    std::cout << nom << "/" << den;
}
int uFraction::gcd(int a, int b) const
{
   if (b == 0) return a;
   return gcd(b, a % b);
}
void uFraction::Reduce()
{
    int gcdVal = gcd(abs(nom), abs(den));
    nom /= gcdVal;
    den /= gcdVal;
}

 uFraction& uFraction::operator+= (const uFraction& first)
{
    nom = first.nom * den + nom * first.den;
    den = first.den * den;
    Reduce();
    return *this;
}

uFraction& uFraction::operator-= (const uFraction& first)
{
    nom = nom * first.den - first.nom * den;
    den = first.den * den;
    Reduce();
    return *this;
}

uFraction& uFraction::operator*= (const uFraction& first)
{
    nom *= first.nom;
    den *= first.den;
    Reduce();
    return *this;
}

uFraction& uFraction::operator/= (const uFraction& first)
{
    nom *= first.den;
    den *= first.nom;
    Reduce();
    return *this;
}
//    void sqrt (uFraction& fract)
//    {
//        nom = sqrt (fract.nom);
//        den = sqrt (fract.den);
//    }

uFraction uFraction::operator+ (const uFraction& second) const
 {
     uFraction result;
     result.nom = nom * second.den + second.nom * den;
     result.den = den * second.den;
     result.Reduce();
     return result;
 }

uFraction uFraction::operator- (const uFraction& second) const
 {
     uFraction result;
     result.nom = nom * second.den - second.nom * den;
     result.den = den * second.den;
     result.Reduce();
     return result;
 }

uFraction uFraction::operator* (const uFraction& second) const
{
    uFraction result;
    result.nom = nom * second.nom;
    result.den = den * second.den;
    result.Reduce();
    return result;
}

uFraction uFraction::operator/ (const uFraction& second) const
{
    uFraction result;
    result.nom = nom * second.den;
    result.den = den * second.nom;
    result.Reduce();
    return result;
}
