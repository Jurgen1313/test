#include "fraction.h"

uFraction::uFraction (): nom (1), den (1)
{
}

uFraction::uFraction (const int nom_, const int den_): nom (nom_), den (den_)
{
    Reduce();
}

void uFraction::setNumerator(const int setValue )
{
    nom = setValue;
    Reduce();
}
void uFraction::setDenominator(const int setValue)
{
        den = setValue;
    if (den == 0)
        den = 1;
    Reduce();
}
void uFraction::setFraction (const int setNom, const int setDen)
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
int gcd(const int a, const int b)
{
   if (b == 0) return a;
   return gcd(b, a % b);
}
void uFraction::Reduce()
{
    int gcdVal = gcd(abs(nom), abs(den));
    nom /= gcdVal;
    den /= gcdVal;
    negativeFraction();
}

void uFraction::negativeFraction()
{
    if (nom != 0 && den < 0)
    {
        nom = -nom;
        den = -den;
    }
    else if (nom == 0)
        den = 1;
}

 uFraction& uFraction::operator+= (const uFraction& first)
{
    nom = first.nom * den + nom * first.den;
    den *= first.den;
    Reduce();
    return *this;
}

uFraction& uFraction::operator-= (const uFraction& first)
{
    nom = nom * first.den - first.nom * den;
    den *= first.den;
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

uFraction operator+ (uFraction first, const uFraction& second)
 {
     return first += second;
 }

uFraction operator- (uFraction first, const uFraction& second)
 {
    return first -= second;
 }

uFraction operator* (uFraction first, const uFraction& second)
{
    return first *= second;
}

uFraction operator/ (uFraction first, const uFraction& second)
{
    return (first /= second);
}

uFraction operator+ (const int number, const uFraction& f)
{
    uFraction result {number, 1};
    result += f;
    result.Reduce();
    return result;
}

uFraction operator- (const int number, const uFraction& f)
{
    uFraction result {number, 1};
    result -= f;
    result.Reduce();
    return result;
}

uFraction operator* (const int number, const uFraction& f)
{
    uFraction result {number, 1};
    result *= f;
    result.Reduce();
    return result;
}

uFraction operator/ (const int number, const uFraction& f)
{
    uFraction result {number, 1};
    result /= f;
    result.Reduce();
    return result;
}

uFraction operator+ (const uFraction& f, const int number)
{
    return number + f;
}

uFraction operator- (const uFraction& f, const int number)
{
    return -number + f;
}

uFraction operator* (const uFraction& f, const int number)
{
    return number * f;
}

uFraction operator/ (const uFraction& f, const int number)
{
    return 1/((1 / f) * number);
}

int uFraction::operator> (const uFraction& second) const
{
    return ((nom * second.den) > (second.nom * den));
}

int uFraction::operator< (const uFraction& second) const
{
    return ((nom * second.den) < (second.nom * den));
}

int uFraction::operator>= (const uFraction& second) const
{
    return ((nom * second.den) >= (second.nom * den));
}

int uFraction::operator<= (const uFraction& second) const
{
    return ((nom * second.den) <= (second.nom * den));
}

std::ostream& operator<< (std::ostream& os, const uFraction& fraction)
{
    os << fraction.nom << "/" << fraction.den;
    return os;
}


