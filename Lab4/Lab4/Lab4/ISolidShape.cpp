#include "ISolidShape.h"

ISolidShape::ISolidShape(double area, double perimeter,
	std::string type, uint32_t outLineColor, uint32_t fillColor)
	:IShape(area, perimeter, type, outLineColor)
	, m_fillColor(fillColor)
{}
uint32_t ISolidShape::GetFillColor()const
{
	return m_fillColor;
}