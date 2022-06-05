#pragma once
#include "ISolidShape.h"
#include "Shape.h"

class SolidShape : public ISolidShape, public Shape
{
public:
	SolidShape(std::string type,
		uint32_t fillColor, uint32_t outlineColor);
	uint32_t GetOutLineColor() const override;
	std::string ToString() const override;
	uint32_t GetFillColor() const override;
private:
	uint32_t m_fillColor;
};