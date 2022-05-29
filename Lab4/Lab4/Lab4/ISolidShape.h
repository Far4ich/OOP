#pragma once
#include "IShape.h"

class ISolidShape : public IShape
{
public:
	ISolidShape(double area, double perimeter, std::string type, uint32_t outLineColor, uint32_t fillColor);
	uint32_t GetFillColor()const;
private:
	uint32_t m_fillColor;

};