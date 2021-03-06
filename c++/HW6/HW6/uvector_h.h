#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <cmath>
//#include "uvector.cpp"


class uVector
{
    private:
    int x1, y1, z1;
    int x2, y2, z2;
    int x, y, z;


    public:
    uVector();
    uVector(const int, const int, const int, const int, const int, const int);
    uVector(const int, const int, const int);
//    ~uVector();

    int getX() const;
    int getY() const;
    int getZ() const;

    double Lenght() const;

    double cosX() const;
    double cosY() const;
    double cosZ() const;

    int Compare(const uVector&) const;
    int ScalarProduct(const uVector&) const;
    double cos_edge(const uVector&) const;

    uVector& operator+= (const uVector&);
    uVector operator+ (const uVector&) const;

    uVector& operator*= (const int);
    uVector operator* (const int) const;
    int operator* (const uVector&) const;
    uVector vector_mul(const uVector&) const;

    uVector& operator-= (const uVector&);
    uVector operator- (const uVector&) const;

    friend std::ostream& operator<< (std::ostream&, const uVector&);
    friend uVector operator* (const int, const uVector&);
};


#endif // FRACTION_H
