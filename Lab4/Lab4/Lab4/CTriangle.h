#pragma once
#include "SolidShape.h"
#include "CPoint.h"

class CTriangle : public SolidShape
{
public:
	CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3,
		uint32_t outLineColor, uint32_t fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;
private:
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};