#define CATCH_CONFIG_MAIN
#include "../../../Catch/catch.hpp"
#include "../Lab4/WorkWithShapes.h"
//todo: проверка расчетов площади и периметра, высоты и ширины
SCENARIO("Add line correct test")
{
	stringstream sStream;
	std::vector<Shape*> shapes;
	const uint32_t outLineColor = 0;

	sStream << "0 20.1 20.2 0 0";
	REQUIRE(AddLine(sStream, shapes, outLineColor));
}

SCENARIO("Add line incorrect test")
{
	stringstream sStream;
	std::vector<Shape*> shapes;
	const uint32_t outLineColor = 0;

	sStream << "";
	REQUIRE(!AddLine(sStream, shapes, outLineColor));
}

SCENARIO("Add rect correct test")
{
	stringstream sStream;
	std::vector<Shape*> shapes;
	const uint32_t outLineColor = 0;
	const uint32_t fillColor = 0;

	sStream << "0 0 20.1 20.2 0 0";
	REQUIRE(AddRectangle(sStream, shapes, outLineColor, fillColor));
}

SCENARIO("Add rect incorrect test")
{
	stringstream sStream;
	std::vector<Shape*> shapes;
	const uint32_t outLineColor = 0;
	const uint32_t fillColor = 0;

	sStream << "";
	REQUIRE(!AddRectangle(sStream, shapes, outLineColor, fillColor));
}

SCENARIO("Add triangle correct test")
{
	stringstream sStream;
	std::vector<Shape*> shapes;
	const uint32_t outLineColor = 0;
	const uint32_t fillColor = 0;

	sStream << "0 0 20.1 20.2 1 1 0 0";
	REQUIRE(AddTriangle(sStream, shapes, outLineColor, fillColor));
}

SCENARIO("Add triangle incorrect test")
{
	stringstream sStream;
	std::vector<Shape*> shapes;
	const uint32_t outLineColor = 0;
	const uint32_t fillColor = 0;

	sStream << "";
	REQUIRE(!AddTriangle(sStream, shapes, outLineColor, fillColor));
}

SCENARIO("Add circle correct test")
{
	stringstream sStream;
	std::vector<Shape*> shapes;
	const uint32_t outLineColor = 0;
	const uint32_t fillColor = 0;

	sStream << "0 0 20.1 20.2 5";
	REQUIRE(AddCircle(sStream, shapes, outLineColor, fillColor));
}

SCENARIO("Add circle incorrect test")
{
	stringstream sStream;
	std::vector<Shape*> shapes;
	const uint32_t outLineColor = 0;
	const uint32_t fillColor = 0;

	sStream << "";
	REQUIRE(!AddCircle(sStream, shapes, outLineColor, fillColor));
}

SCENARIO("GetBiggestAreaShape correct test")
{
	stringstream sStream;
	std::vector<Shape*> shapes;
	const uint32_t outLineColor = 0;
	const uint32_t fillColor = 0;

	sStream << "0 0 20.1 20.2 15";
	AddCircle(sStream, shapes, outLineColor, fillColor);

	sStream.str("");
	sStream << "0 0 20.1 20.2 1 1 0 0";
	AddTriangle(sStream, shapes, outLineColor, fillColor);

	REQUIRE(shapes[0] == GetBiggestAreaShape(shapes));
}

SCENARIO("GetBiggestAreaShape null test")
{
	std::vector<Shape*> shapes;

	REQUIRE(nullptr == GetBiggestAreaShape(shapes));
}

SCENARIO("GetSmallestPerimeterShape correct test")
{
	stringstream sStream;
	std::vector<Shape*> shapes;
	const uint32_t outLineColor = 0;
	const uint32_t fillColor = 0;

	sStream << "0 0 20.1 20.2 15";
	AddCircle(sStream, shapes, outLineColor, fillColor);

	sStream.str("");
	sStream << "0 0 20.1 20.2 1 1 0 0";
	AddTriangle(sStream, shapes, outLineColor, fillColor);

	REQUIRE(shapes[1] == GetSmallestPerimeterShape(shapes));
}

SCENARIO("GetSmallestPerimeterShape null test")
{
	std::vector<Shape*> shapes;

	REQUIRE(nullptr == GetSmallestPerimeterShape(shapes));
}