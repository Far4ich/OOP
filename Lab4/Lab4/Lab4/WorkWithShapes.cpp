#include "CRectangle.h"
#include "CTriangle.h"
#include "CCircle.h"
#include "CLineSegment.h"
#include <sstream>
#include <string>
#include <algorithm>
#include "WorkWithShapes.h"
#include <iostream>
#include <cmath>

bool AddLine(std::stringstream& sStream, std::vector<Shape*>& shapes, const uint32_t& outLineColor)
{
	CPoint startPoint;
	CPoint endPoint;

	string in = sStream.str();
	if (count(in.begin(), in.end(), ' ') == 4)
	{
		sStream >> startPoint.x >> startPoint.y;
		sStream >> endPoint.x >> endPoint.y;
		shapes.push_back(new ClineSegment(startPoint, endPoint, outLineColor));
		return true;
	}

	return false;
}

bool AddRectangle(std::stringstream& sStream, std::vector<Shape*>& shapes, const uint32_t& outLineColor, const uint32_t& fillColor)
{
	CPoint leftTop;
	CPoint rightBottom;

	string in = sStream.str();
	if (count(in.begin(), in.end(), ' ') == 5)
	{
		sStream >> leftTop.x >> leftTop.y;
		sStream >> rightBottom.x >> rightBottom.y;
		shapes.push_back(new CRectangle(leftTop, rightBottom, outLineColor, fillColor));
		return true;
	}
	return false;
}

bool AddTriangle(std::stringstream& sStream, std::vector<Shape*>& shapes, const uint32_t& outLineColor, const uint32_t& fillColor)
{
	CPoint vertex1;
	CPoint vertex2;
	CPoint vertex3;

	string in = sStream.str();
	if (count(in.begin(), in.end(), ' ') == 7)
	{
		sStream >> vertex1.x >> vertex1.y;
		sStream >> vertex2.x >> vertex2.y;
		sStream >> vertex3.x >> vertex3.y;
		shapes.push_back(new CTriangle(vertex1, vertex2, vertex3, outLineColor, fillColor));
		return true;
	}
	return false;
}

bool AddCircle(std::stringstream& sStream, std::vector<Shape*>& shapes, const uint32_t& outLineColor, const uint32_t& fillColor)
{
	CPoint center;
	double radius;

	string in = sStream.str();
	if (count(in.begin(), in.end(), ' ') == 4)
	{
		sStream >> center.x >> center.y;
		sStream >> radius;
		shapes.push_back(new CCircle(center, radius, outLineColor, fillColor));
		return true;
	}
	return false;
}

bool AddShape(const string in, vector<Shape*>& shapes)
{
	string type;
	size_t pos = in.find(" ");
	type.append(in, 0, pos);

	string inLine;
	inLine.append(in, pos + 1);
	stringstream sStream;
	sStream << inLine;

	uint32_t outLineColor;
	sStream >> hex >> outLineColor >> dec;
	//контроллер посмотреть у Малова
	//функция добавления с парсингом
	if (type == "line")
	{
		return AddLine(sStream, shapes, outLineColor);
	}

	uint32_t fillColor;
	sStream >> hex >> fillColor >> dec;

	if (type == "rectangle")
	{
		return AddRectangle(sStream, shapes, outLineColor, fillColor);
	}
	if (type == "triangle")
	{
		return AddTriangle(sStream, shapes, outLineColor, fillColor);
	}
	if (type == "circle")
	{
		return AddCircle(sStream, shapes, outLineColor, fillColor);
	}

	return false;
}

static bool AreaComparer(Shape* a, Shape* b)
{
	return a->GetArea() < b->GetArea();
}

Shape* GetBiggestAreaShape(const std::vector<Shape*> shapes)
{
	if (shapes.size() != 0)
	{
		auto result = max_element(shapes.begin(), shapes.end(), AreaComparer);
		//
		return *result;//shapes[distance(shapes.begin(), result)];
	}
	return nullptr;
}
static bool PerimeterComparer(Shape* a, Shape* b)
{
	return a->GetPerimeter() < b->GetPerimeter();
}

Shape* GetSmallestPerimeterShape(const std::vector<Shape*> shapes)
{
	if (shapes.size() != 0)
	{
		auto result = min_element(shapes.begin(), shapes.end(), PerimeterComparer);
		return *result;//shapes[distance(shapes.begin(), result)];
	}
	return nullptr;
}

void PrintShape(Shape* shape)
{//ToString() вывод данных о фигуре
	cout << shape->ToString() << "\n";
	cout << "Area = " << shape->GetArea() << " Perimeter = " << shape->GetPerimeter() << "\n";

	if (shape->ToString() == "line")
	{
		ClineSegment* line = static_cast<ClineSegment*>(shape);
		cout << "Outline color = " << hex << line->GetOutLineColor() << dec << "\n";
		cout << "Start point (" << line->GetStartPoint().x << ", " << line->GetStartPoint().y 
			<< ") End point (" << line->GetEndPoint().x << ", " << line->GetEndPoint().y << ")\n\n";
		return;
	}

	if (shape->ToString() == "rectangle")
	{
		CRectangle* rect = static_cast<CRectangle*>(shape);
		cout << "Outline color = " << hex << shape->GetOutLineColor();
		cout << " Fill color = " << rect->GetFillColor() << dec << "\n";
		cout << "Left top (" << rect->GetLeftTop().x << ", " << rect->GetLeftTop().y << ") RightBottom (" << rect->GetRightBottom().x << ", " << rect->GetRightBottom().y << ")\n";
		cout << "Width = " << rect->GetWidth() << " Height = " << rect->GetHeight() << "\n\n";
		return;
	}

	if (shape->ToString() == "circle")
	{
		CCircle* circle = static_cast<CCircle*>(shape);
		cout << "Outline color = " << hex << shape->GetOutLineColor();
		cout << " Fill color = " << circle->GetFillColor() << dec << "\n";
		cout << "Center(" << circle->GetCenter().x << ", " << circle->GetCenter().y << ") radius = " << circle->GetRadius() << "\n\n";
		return;
	}

	if (shape->ToString() == "triangle")
	{
		CTriangle* triangle = static_cast<CTriangle*>(shape);
		cout << "Outline color = " << hex << shape->GetOutLineColor();
		cout << " Fill color = " << triangle->GetFillColor() << dec << "\n";
		cout << "Vertex1 (" << triangle->GetVertex1().x << ", " << triangle->GetVertex1().y << ") Vertex2 (" << triangle->GetVertex2().x << ", " << triangle->GetVertex2().y << ") Vertex3 (" << triangle->GetVertex3().x << ", " << triangle->GetVertex3().y << ")\n\n";
	}
}