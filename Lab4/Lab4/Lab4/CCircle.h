#pragma once
#include "SolidShape.h"
#include "CPoint.h"

class CCircle : public SolidShape
{
public:
	CCircle(CPoint center, double radius, uint32_t outLineColor, uint32_t fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	CPoint GetCenter() const;
	double GetRadius() const;
private:
	CPoint m_center;
	double m_radius;
};