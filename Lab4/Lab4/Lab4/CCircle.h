#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

class CCircle : public ISolidShape
{
public:
	CCircle(CPoint center, double radius, uint32_t outLineColor, uint32_t fillColor);
	CPoint GetCenter() const;
	double GetRadius() const;
private:
	CPoint m_center;
	double m_radius;
	double FindArea(double radius);
	double FindPerimeter(double radius);
};