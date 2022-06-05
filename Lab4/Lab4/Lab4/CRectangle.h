#pragma once
#include "SolidShape.h"
#include "CPoint.h"

class CRectangle : public SolidShape
{
public:
	CRectangle(CPoint leftTop, CPoint rightBottom, uint32_t outLineColor, uint32_t fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;
private:
	CPoint m_leftTop;
	CPoint m_rightBottom;
};