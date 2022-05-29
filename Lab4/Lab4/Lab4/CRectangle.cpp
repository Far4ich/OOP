#include "CRectangle.h"

CRectangle::CRectangle(CPoint leftTop, CPoint rightBottom, uint32_t outLineColor, uint32_t fillColor)
	:ISolidShape(FindArea(leftTop, rightBottom), FindPerimeter(leftTop, rightBottom), "Rectangle", outLineColor, fillColor)
	, m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
	, m_width(abs(rightBottom.x - leftTop.x))
	, m_height(abs(rightBottom.y - leftTop.y))
{}
CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}
CPoint CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}
double CRectangle::GetWidth() const
{
	return m_width;
}
double CRectangle::GetHeight() const
{
	return m_height;
}

double CRectangle::FindArea(CPoint leftTop, CPoint rightBottom)
{
	return abs(rightBottom.x - leftTop.x) * abs(rightBottom.y - leftTop.y);
}

double CRectangle::FindPerimeter(CPoint leftTop, CPoint rightBottom)
{
	return abs(rightBottom.x - leftTop.x) * 2 + abs(rightBottom.y - leftTop.y) * 2;
}