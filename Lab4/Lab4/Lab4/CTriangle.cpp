#include "CTriangle.h"

CTriangle::CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3,
	uint32_t outLineColor, uint32_t fillColor)
	: ISolidShape(FindArea(vertex1, vertex2, vertex3),
		FindPerimeter(vertex1, vertex2, vertex3),
		"Triangle", outLineColor, fillColor)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{}
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
double CTriangle::FindArea(CPoint vertex1, CPoint vertex2, CPoint vertex3)
{
	return 0.5 * ((vertex1.x - vertex3.x) * (vertex2.y - vertex3.y)
		- (vertex2.x - vertex3.x) * (vertex1.y - vertex3.y));
}

double CTriangle::FindPerimeter(CPoint vertex1, CPoint vertex2, CPoint vertex3)
{
	return (vertex1.GetDistance(vertex2) + vertex2.GetDistance(vertex3)
		+ vertex3.GetDistance(vertex1));
}