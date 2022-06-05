#include "CCircle.h"

const double pi = 3.14;

CCircle::CCircle(CPoint center, double radius, uint32_t outLineColor, uint32_t fillColor)
	:SolidShape("circle", outLineColor, fillColor)
	, m_center(center)
	, m_radius(radius)
{
}
double CCircle::GetArea() const
{
	return pi * m_radius * m_radius / 2;
}
double CCircle::GetPerimeter() const
{
	return 2 * pi * m_radius;
}
CPoint CCircle::GetCenter() const
{
	return m_center;
}
double CCircle::GetRadius() const
{
	return m_radius;
}