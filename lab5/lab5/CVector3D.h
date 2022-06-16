#pragma once
#include <iostream>
#include <fstream>
#include "float.h"

class CVector3D
{
public:
    CVector3D();

    CVector3D(double x0, double y0, double z0);

    double GetLength()const;

    void Normalize();

    CVector3D operator +() const;

    CVector3D operator -() const;

    CVector3D operator +(CVector3D const& vector2) const;

    CVector3D operator -(CVector3D const& vector2) const;

    CVector3D operator *(double scalar)const;

    CVector3D operator /(double scalar)const;

    CVector3D& operator +=(CVector3D const& vector2);

    CVector3D& operator -=(CVector3D const& vector2);

    CVector3D& operator *=(double scalar);

    CVector3D& operator /=(double scalar);

    bool operator ==(CVector3D const& vector2);

    bool operator !=(CVector3D const& vector2);

    friend std::istream& operator>>(std::istream& in, CVector3D& v);

    friend std::ostream& operator<<(std::ostream& out, CVector3D v);

    double x, y, z;
};

CVector3D operator *(double scalar, CVector3D const& vector2);

CVector3D Normalize(CVector3D const& v);

double DotProduct(CVector3D const& v1, CVector3D const& v2);

CVector3D CrossProduct(CVector3D const& v1, CVector3D const& v2);
