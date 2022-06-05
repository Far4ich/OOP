#include "CTriangle.h"

CTriangle::CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3,
	uint32_t outLineColor, uint32_t fillColor)
	: SolidShape("rectangle", fillColor, outLineColor)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{}

double CTriangle::GetArea() const
{
	return 0.5 * ((m_vertex1.x - m_vertex3.x) * (m_vertex2.y - m_vertex3.y)
		- (m_vertex2.x - m_vertex3.x) * (m_vertex1.y - m_vertex3.y));
}
double CTriangle::GetPerimeter() const
{
	return m_vertex1.GetDistance(m_vertex2) + m_vertex2.GetDistance(m_vertex3)
		+ m_vertex3.GetDistance(m_vertex1);
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}
CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}
CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}