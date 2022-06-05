#include "CRectangle.h"

CRectangle::CRectangle(CPoint leftTop, CPoint rightBottom, uint32_t outLineColor, uint32_t fillColor)
	:SolidShape("rectangle", fillColor, outLineColor)
	, m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
{
}

double CRectangle::GetArea() const
{
	return abs(m_rightBottom.x - m_leftTop.x) * abs(m_rightBottom.y - m_leftTop.y);
}
double CRectangle::GetPerimeter() const
{
	return abs(m_rightBottom.x - m_leftTop.x) * 2 + abs(m_rightBottom.y - m_leftTop.y) * 2;
}
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
	return abs(m_rightBottom.x - m_leftTop.x);
}
double CRectangle::GetHeight() const
{
	return abs(m_rightBottom.y - m_leftTop.y);
}