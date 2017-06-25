#include "uvector_h.h"


    uVector::uVector()
    {
        x1 = y1 = 0;
        x2 = y2 = 0;
        z1 = z2 = 0;
        x = x2 - x1;
        y = y2 - y1;
        z = z2 - z1;
    }
    uVector::uVector(const int x1_, const int y1_ , const int x2_, const int y2_, const int z1_ = 0, const int z2_ = 0)
    {
        x1 = x1_;
        y1 = y1_;
        z1 = z1_;
        x2 = x2_;
        y2 = y2_;
        z2 = z2_;
        x = x2 - x1;
        y = y2 - y1;
        z = z2 - z1;
    }
    uVector::uVector(const int x_, const int y_ , const int z_)
    {
        x1 = 0;
        y1 = 0;
        z1 = 0;
        x2 = 0;
        y2 = 0;
        z2 = 0;
        x = x_;
        y = y_;
        z = z_;
    }
    int uVector::getX() const
    {
        return x;
    }
    int uVector::getY() const
    {
        return y;
    }
    int uVector::getZ() const
    {
        return z;
    }

    double uVector::Lenght() const
    {
        return sqrt((double)(pow(x, 2) + pow(y, 2) + pow(z, 2)));
    }
    double uVector::cosX() const
    {
        return (x)/Lenght();
    }
    double uVector::cosY() const
    {
        return (y)/Lenght();
    }
    double uVector::cosZ() const
    {
        return (z)/Lenght();
    }
    int uVector::Compare(const uVector& second) const
    {
         return (second.y == x) && (second.y == y) && (second.z == y);
    }
    int uVector::ScalarProduct(const uVector& second) const
    {
        return (x * second.x + y * second.y + z * second.z);
    }

    //ADD
    uVector& uVector::operator+= (const uVector& second)
    {
        x += second.x;
        y += second.y;
        z += second.z;
        return *this;
    }

    uVector uVector::operator+ (const uVector& second) const
    {
        uVector tmp;
        tmp.x = x + second.x;
        tmp.y = y + second.y;
        tmp.z = z + second.z;
        return tmp;
    }

    //SUB
    uVector& uVector::operator-= (const uVector& second)
    {
        x -= second.x;
        y -= second.y;
        z -= second.z;
        return *this;
    }

    uVector uVector::operator- (const uVector& second) const
    {
        return (*this +  (second * (-1)));
    }

    uVector& uVector::operator*= (const int number)
    {
        x *= number;
        y *= number;
        z *= number;
//        return (*this * number);
        return *this;
    }

    uVector uVector::operator* (const int number) const
    {
        uVector tmp;
        tmp.x = x * number;
        tmp.y = y * number;
        tmp.z = z * number;
        return tmp;
    }
