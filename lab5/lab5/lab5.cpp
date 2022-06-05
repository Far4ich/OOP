#include <iostream>
#include "float.h"

class CVector3D
{
    CVector3D()
        :x(0), y(0), z(0)
    {}

    CVector3D(double x0, double y0, double z0)
        :x(x0), y(y0), z(z0)
    {}

    double GetLength()const
    {
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }

    void Normalize()
    {
        double length = GetLength();
        x /= length;
        y /= length;
        z /= length;
    }

    bool IsNull() 
    {
        return x == 0 && y == 0 && z == 0;
    }

    CVector3D operator +() const
    {
        return CVector3D(x, y, z);
    }

    CVector3D operator -() const
    {
        return CVector3D(-x, -y, -z);
    }

    CVector3D operator +(CVector3D const& vector2) const
    {
        return CVector3D(x + vector2.x, y + vector2.y, z + vector2.z);
    }

    CVector3D operator -(CVector3D const& vector2) const
    {
        return CVector3D(x - vector2.x, y - vector2.y, z - vector2.z);
    }

    CVector3D operator *(double scalar)const
    {
        return CVector3D(x * scalar, y * scalar, z * scalar);
    }

    CVector3D operator /(double scalar)const
    {
        return CVector3D(x / scalar, y / scalar, z / scalar);
    }

    CVector3D& operator +=(CVector3D const& vector2)
    {
        x += vector2.x;
        y += vector2.y;
        z += vector2.z;

        return *this;
    }

    CVector3D& operator -=(CVector3D const& vector2)
    {
        x -= vector2.x;
        y -= vector2.y;
        z -= vector2.z;

        return *this;
    }

    CVector3D& operator *=(double scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;

        return *this;
    }

    CVector3D& operator /=(double scalar)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;

        return *this;
    }

    bool operator ==(CVector3D const& vector2)
    {
        
    }

    double x, y, z;
};


CVector3D operator *(double scalar, CVector3D const& vector2)
{
    return vector2 * scalar;
}


int main()
{
    CVector3D vector(1.2, 2, 12);


}
