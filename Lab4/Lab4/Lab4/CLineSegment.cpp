#include "CLineSegment.h"


ClineSegment::ClineSegment(CPoint startPoint, CPoint endPoint, uint32_t outLineColor)
	: IShape(0, startPoint.GetDistance(endPoint), "LineSegment", outLineColor)
	, m_startPoint(startPoint)
	, m_endPoint(endPoint)
{}
CPoint ClineSegment::GetStartPoint() const
{
	return m_startPoint;
}
CPoint ClineSegment::GetEndPoint() const
{
	return m_endPoint;
}