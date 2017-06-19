#include "fraction.h"

uFraction::uFraction ()
{
    nom = 1;
    den = 1;
}

uFraction::uFraction (const int nom_, const int den_)
{
    nom = nom_;
    den = den_;
    negativeFraction();
}

void uFraction::setNumerator(const int setValue )
{
    nom = setValue;
}
void uFraction::setDenominator(const int setValue)
{
    den = setValue;
    negativeFraction();
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
int uFraction::gcd(const int a, const int b) const
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
        nom *= -1;
        den *= -1;
    }
    else if (nom == 0)
        den = 1;
}

uFraction uFraction::aProgression(const int n, const int d) const
{
    uFraction result;
    result.nom = (n/2)*(2*nom+d*(n-1));
    result.den = den;
    result.Reduce();
    return result;
}

uFraction uFraction::aProgression(const uFraction& second, const int n) const
{
    uFraction result {n,2};
    result *= (*this + second);
    result.Reduce();
    return result;
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

uFraction uFraction::operator+ (const int number) const
{
    uFraction result {number, 1};
    result += *this;
    result.Reduce();
    return result;
}

uFraction uFraction::operator- (const int number) const
{
    uFraction result {number, 1};
    result = *this - result;
    result.Reduce();
    return result;
}

uFraction uFraction::operator* (const int number) const
{
    uFraction result {number, 1};
    result *= *this;
    result.Reduce();
    return result;
}

uFraction uFraction::operator/ (const int number) const
{
    uFraction result {number, 1};
    result = *this / result;
    result.Reduce();
    return result;
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

uFraction uFraction::operator^ (const int power) const
{
    uFraction result;
    result.nom = pow(nom, power) ;
    result.den = pow(den, power);
    result.Reduce();
    return result;
}

uFraction uFraction::operator^ (const uFraction& power) const
{
    uFraction result;
    result.nom = pow(nom, power.nom/power.den) ;
    result.den = pow(den, power.nom/power.den);
    result.Reduce();
    return result;
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

std::ostream& operator<< (std::ostream& os, const uFraction& f)
{

    os << f.nom << "/" << f.den;
    return os;
}


