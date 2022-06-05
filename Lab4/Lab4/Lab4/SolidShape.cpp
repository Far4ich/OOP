#include "SolidShape.h"

SolidShape::SolidShape(std::string type,
	uint32_t fillColor, uint32_t outlineColor)
	:Shape(type, outlineColor)
	, m_fillColor(fillColor)
{
}

uint32_t SolidShape::GetFillColor() const
{
	return m_fillColor;
}

uint32_t SolidShape::GetOutLineColor() const
{
	return Shape::GetOutLineColor();
}
std::string SolidShape::ToString() const
{
	return Shape::ToString();
}