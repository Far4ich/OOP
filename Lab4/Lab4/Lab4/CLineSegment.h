#pragma once
#include "Shape.h"
#include "CPoint.h"

class ClineSegment : public Shape
{
public:
	ClineSegment(CPoint startPoint, CPoint endPoint, uint32_t outLineColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
private:
	CPoint m_startPoint;
	CPoint m_endPoint;
};