#pragma once
#include <string>

class IShape
{
public:
    IShape(double area, double perimeter, std::string type, uint32_t outLineColor);
    double GetArea() const;
    double GetPerimeter() const;
    std::string ToString() const;
    uint32_t GetOutLineColor() const;
private:
    double m_area;
    double m_perimeter;
    std::string m_type;
    uint32_t m_outLineColor;
};