#include "IShape.h"


IShape::IShape(double area, double perimeter, std::string type, uint32_t outLineColor)
{
    m_area = area;
    m_perimeter = perimeter;
    m_type = type;
    m_outLineColor = outLineColor;
}
double IShape::GetArea() const
{
    return m_area;
}
double IShape::GetPerimeter() const
{
    return m_perimeter;
}
std::string IShape::ToString() const
{
    return m_type;
}
uint32_t IShape::GetOutLineColor() const
{
    return m_outLineColor;
}