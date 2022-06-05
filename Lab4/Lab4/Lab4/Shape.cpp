#include "Shape.h"

Shape::Shape(std::string type, uint32_t outlineColor)
	:m_type(type)
	,m_outLineColor(outlineColor)
{}
std::string Shape::ToString() const
{
	return m_type;
}
uint32_t Shape::GetOutLineColor() const
{
	return m_outLineColor;
}