#include "CLineSegment.h"


ClineSegment::ClineSegment(CPoint startPoint, CPoint endPoint, uint32_t outLineColor)
	: Shape("line", outLineColor)
	, m_startPoint(startPoint)
	, m_endPoint(endPoint)
{
}
double ClineSegment::GetArea() const
{
	return 0;
}

double ClineSegment::GetPerimeter() const
{
	return m_startPoint.GetDistance(m_endPoint);
}

CPoint ClineSegment::GetStartPoint() const
{
	return m_startPoint;
}
CPoint ClineSegment::GetEndPoint() const
{
	return m_endPoint;
}