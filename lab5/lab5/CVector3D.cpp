#include "CVector3D.h"

CVector3D::CVector3D()
    :x(0), y(0), z(0)
{}

CVector3D::CVector3D(double x0, double y0, double z0)
    :x(x0), y(y0), z(z0)
{}

double CVector3D::GetLength()const
{
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

void CVector3D::Normalize()
{
    double length = GetLength();
    if (length != 0)
    {
        x /= length;
        y /= length;
        z /= length;
    }
}

CVector3D CVector3D::operator +() const
{
    return *this;
}

CVector3D CVector3D::operator -() const
{
    return CVector3D(-x, -y, -z);
}

CVector3D CVector3D::operator +(CVector3D const& vector2) const
{
    return CVector3D(x + vector2.x, y + vector2.y, z + vector2.z);
}

CVector3D CVector3D::operator -(CVector3D const& vector2) const
{
    return CVector3D(x - vector2.x, y - vector2.y, z - vector2.z);
}

CVector3D CVector3D::operator *(double scalar)const
{
    return CVector3D(x * scalar, y * scalar, z * scalar);
}

CVector3D CVector3D::operator /(double scalar)const
{
    return CVector3D(x / scalar, y / scalar, z / scalar);
}

CVector3D& CVector3D::operator +=(CVector3D const& vector2)
{
    x += vector2.x;
    y += vector2.y;
    z += vector2.z;

    return *this;
}

CVector3D& CVector3D::operator -=(CVector3D const& vector2)
{
    x -= vector2.x;
    y -= vector2.y;
    z -= vector2.z;

    return *this;
}

CVector3D& CVector3D::operator *=(double scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

CVector3D& CVector3D::operator /=(double scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;

    return *this;
}

bool CVector3D::operator ==(CVector3D const& vector2)
{
    return abs(x - vector2.x) <= DBL_EPSILON && abs(y - vector2.y) <= DBL_EPSILON && abs(z - vector2.z) <= DBL_EPSILON;
}

bool CVector3D::operator !=(CVector3D const& vector2)
{
    return !(*this == vector2);
}

CVector3D operator *(double scalar, CVector3D const& vector2)
{
    return vector2 * scalar;
}

CVector3D Normalize(CVector3D const& v)
{
    double length = v.GetLength();
    if (length != 0)
    {
        return v / length;
    }
    return v;
}

double DotProduct(CVector3D const& v1, CVector3D const& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

CVector3D CrossProduct(CVector3D const& v1, CVector3D const& v2)
{
    return CVector3D(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}