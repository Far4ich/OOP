#pragma once
#include "IShape.h"
#include "CPoint.h"

class ClineSegment : public IShape
{
public:
	ClineSegment(CPoint startPoint, CPoint endPoint, uint32_t outLineColor);
	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
private:
	CPoint m_startPoint;
	CPoint m_endPoint;
};