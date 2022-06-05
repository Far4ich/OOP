#pragma once
#include "Shape.h"
#include <vector>

using namespace std;

bool AddLine(std::stringstream& sStream, std::vector<Shape*>& shapes, const uint32_t& outLineColor);

bool AddRectangle(std::stringstream& sStream, std::vector<Shape*>& shapes, const uint32_t& outLineColor, const uint32_t& fillColor);

bool AddTriangle(std::stringstream& sStream, std::vector<Shape*>& shapes, const uint32_t& outLineColor, const uint32_t& fillColor);

bool AddCircle(std::stringstream& sStream, std::vector<Shape*>& shapes, const uint32_t& outLineColor, const uint32_t& fillColor);

bool AddShape(const string in, vector<Shape*>& shapes);

Shape* GetBiggestAreaShape(const std::vector<Shape*> shapes);

Shape* GetSmallestPerimeterShape(const std::vector<Shape*> shapes);

void PrintShape(Shape* shape);