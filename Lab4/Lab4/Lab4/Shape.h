#pragma once
#include "IShape.h"

class Shape : public IShape
{
public:
	Shape(std::string type, uint32_t outlineColor);

	std::string ToString() const override;
	uint32_t GetOutLineColor() const override;
private:
	std::string m_type;
	uint32_t m_outLineColor;
};