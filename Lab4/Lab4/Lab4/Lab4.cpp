#include <iostream>
#include <vector>
#include "CRectangle.h"
#include "CTriangle.h"
#include "CCircle.h"
#include "CLineSegment.h"
#include <sstream>
#include <string>

using namespace std;

bool AddLine(std::stringstream& sStream, std::vector<IShape*>& shapes, const uint32_t& outLineColor)
{
	CPoint startPoint;
	CPoint endPoint;

	sStream >> startPoint.x >> startPoint.y;
	sStream >> endPoint.x >> endPoint.y;
	shapes.push_back(new ClineSegment(startPoint, endPoint, outLineColor));
	return true;
}

bool AddRectangle(std::stringstream& sStream, std::vector<IShape*>& shapes, const uint32_t& outLineColor, const uint32_t& fillColor)
{
	CPoint leftTop;
	CPoint rightBottom;

	sStream >> leftTop.x >> leftTop.y;
	sStream >> rightBottom.x >> rightBottom.y;

	shapes.push_back(new CRectangle(leftTop, rightBottom, outLineColor, fillColor));
	return true;
}

bool AddTriangle(std::stringstream& sStream, std::vector<IShape*>& shapes, const uint32_t& outLineColor, const uint32_t& fillColor)
{
	CPoint vertex1;
	CPoint vertex2;
	CPoint vertex3;

	sStream >> vertex1.x >> vertex1.y;
	sStream >> vertex2.x >> vertex2.y;
	sStream >> vertex3.x >> vertex3.y;

	shapes.push_back(new CTriangle(vertex1, vertex2, vertex3, outLineColor, fillColor));
	return true;
}

bool AddCircle(std::stringstream& sStream, std::vector<IShape*>& shapes, const uint32_t& outLineColor, const uint32_t& fillColor)
{
	CPoint center;
	double radius;

	sStream >> center.x >> center.y;
	sStream >> radius;
	shapes.push_back(new CCircle(center, radius, outLineColor, fillColor));
	return true;
}

bool AddShape(const string in, vector<IShape*>& shapes)
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

IShape* GetBiggestAreaShape(const std::vector<IShape*> shapes)
{
	IShape* bigestAreaShape = nullptr;
	for (IShape* shape : shapes)
	{
		if (bigestAreaShape != nullptr)
		{
			if (shape->GetArea() > bigestAreaShape->GetArea())
			{
				bigestAreaShape = shape;
			}
		}
		else
		{
			bigestAreaShape = shape;
		}
	}
	return bigestAreaShape;
}

IShape* GetSmallestPerimeterShape(const std::vector<IShape*> shapes)
{
	IShape* smallestPerimeterShape = nullptr;
	for (IShape* shape : shapes)
	{
		if (smallestPerimeterShape != nullptr)
		{
			if (shape->GetPerimeter() < smallestPerimeterShape->GetPerimeter())
			{
				smallestPerimeterShape = shape;
			}
		}
		else
		{
			smallestPerimeterShape = shape;
		}
	}
	return smallestPerimeterShape;
}

void PrintShape(IShape* shape)
{
	cout << shape->ToString() << "\n";
	cout << "Area = " << shape->GetArea() << " Perimeter = " << shape->GetPerimeter() << "\n";

	if (shape->ToString() == "LineSegment")
	{
		ClineSegment* line = static_cast<ClineSegment*>(shape);
		cout << "Outline color = " << hex << line->GetOutLineColor() << dec << "\n";
		cout << "Start point (" << line->GetStartPoint().x << ", " << line->GetStartPoint().y << ") End point (" << line->GetEndPoint().x <<", " << line->GetEndPoint().y << ")\n\n";
	}

	if (shape->ToString() == "Rectangle")
	{
		CRectangle* rect = static_cast<CRectangle*>(shape);
		cout << "Outline color = " << hex << shape->GetOutLineColor();
		cout << " Fill color = " << rect->GetFillColor() << dec << "\n";
		cout << "Left top (" << rect->GetLeftTop().x << ", " << rect->GetLeftTop().y << ") RightBottom (" << rect->GetRightBottom().x << ", " << rect->GetRightBottom().y << ")\n";
		cout << "Width = " << rect->GetWidth() << " Height = " << rect->GetHeight() << "\n\n";
	}

	if (shape->ToString() == "Circle")
	{
		CCircle* circle = static_cast<CCircle*>(shape);
		cout << "Outline color = " << hex << shape->GetOutLineColor();
		cout << " Fill color = " << circle->GetFillColor() << dec << "\n";
		cout << "Center = " << circle->GetCenter().x << " radius = " << circle->GetRadius()<< "\n\n";
	}

	if (shape->ToString() == "Triangle")
	{
		CTriangle* triangle = static_cast<CTriangle*>(shape);
		cout << "Outline color = " << hex << shape->GetOutLineColor();
		cout << " Fill color = " << triangle->GetFillColor() << dec << "\n";
		cout << "Vertex1 (" << triangle->GetVertex1().x << ", " << triangle->GetVertex1().y << ") Vertex2 (" << triangle->GetVertex2().x << ", " << triangle->GetVertex2().y << ") Vertex3 (" << triangle->GetVertex3().x << ", " << triangle->GetVertex3().y << ")\n\n";
	}
}

int main()
{
	string in;
	vector<IShape*> shapes;

	while (getline(cin, in))
	{
		if (AddShape(in, shapes))
		{
			cout << "Shape added\n";
		}
		else
		{
			cout << "Incorect shape format\n"
				<< "Formats: \n"
				<< "line <outline color> <start point x> <start point y> <end point x> <end point y>\n"
				<< "rectangle <outline color> <fill color> <left top x> <left top y> <right bottom x> <right bottom y>\n"
				<< "triangle <outline color> <fill color> <vertex1 x> <vertex1 y> <vertex2 x> <vertex2 y> <vertex3 x> <vertex3 y>\n"
				<< "circle <outline color> <fill color> <center x> <center y> <radius>\n";
		}
	}

	PrintShape(GetBiggestAreaShape(shapes));

	PrintShape(GetSmallestPerimeterShape(shapes));

	//for (IShape* shape : shapes)
	//{Саня сказал: "Закоментить, потому что это бесполезно."
	//	PrintShape(shape);
	//}

	return 0;
}


