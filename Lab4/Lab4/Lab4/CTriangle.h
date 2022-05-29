#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

class CTriangle : public ISolidShape
{
public:
	CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3,
		uint32_t outLineColor, uint32_t fillColor);
	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;
private:
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
	double FindArea(CPoint vertex1, CPoint vertex2, CPoint vertex3);
	double FindPerimeter(CPoint vertex1, CPoint vertex2, CPoint vertex3);
};