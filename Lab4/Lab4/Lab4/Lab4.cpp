#include "WorkWithShapes.h"
#include <iostream>

int main()
{
	string in;
	vector<Shape*> shapes;

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

	return 0;
}


