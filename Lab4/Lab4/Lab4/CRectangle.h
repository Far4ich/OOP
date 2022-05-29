#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle(CPoint leftTop, CPoint rightBottom, uint32_t outLineColor, uint32_t fillColor);
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;
private:
	CPoint m_leftTop;
	CPoint m_rightBottom;
	double m_width;
	double m_height;
	double FindArea(CPoint leftTop, CPoint rightBottom);
	double FindPerimeter(CPoint leftTop, CPoint rightBottom);
};