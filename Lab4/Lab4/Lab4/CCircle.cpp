#include "CCircle.h"

const double pi = 3.14;

CCircle::CCircle(CPoint center, double radius, uint32_t outLineColor, uint32_t fillColor)
	:ISolidShape(FindArea(radius), FindPerimeter(radius), "Circle", outLineColor, fillColor)
	, m_center(center)
	, m_radius(radius)
{}
CPoint CCircle::GetCenter() const
{
	return m_center;
}
double CCircle::GetRadius() const
{
	return m_radius;
}
double CCircle::FindArea(double radius)
{
	return pi * radius * radius / 2;
}

double CCircle::FindPerimeter(double radius)
{
	return 2 * pi * radius;
}