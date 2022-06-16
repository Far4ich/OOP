#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../Catch/catch.hpp"
#include "../Lab2_1/WorkWithVector.h"

//тест на пустой массив
//AddAverage tests
SCENARIO("Adding average of empty vector")
{
	std::vector<double> data = {};
	std::vector<double> result = data;

	REQUIRE(AddAverage(data) == result);
}

SCENARIO("Adding average of vector consist of minus values")
{
	std::vector<double> data = { -12.432, -121.12, -1.0 };
	std::vector<double> result = data;

	REQUIRE(AddAverage(data) == result);
}

SCENARIO("Adding average of vector consist of 1")
{
	std::vector<double> data = {1.0, 1.0, 1.0 };
	std::vector<double> result = { 2.0, 2.0, 2.0 };

	REQUIRE(AddAverage(data) == result);
}

SCENARIO("Adding INT overflow average")
{
	std::vector<double> data = { INT_MAX, INT_MAX, INT_MAX };
	std::vector<double> result = { INT_MAX, INT_MAX, INT_MAX };

	REQUIRE(AddAverage(data) == result);
}

//ToAscendingOrder
SCENARIO("To ascending order for empty vector")
{
	std::vector<double> data = { 1.0, 2.0, 5.0 };
	std::vector<double> result = data;
	REQUIRE(ToAscendingOrder(data) == result);
}

SCENARIO("To ascending order for vector whom is already take ascending order")
{
	std::vector<double> data = { 1.0, 2.0, 5.0 };
	std::vector<double> result = data;
	REQUIRE(ToAscendingOrder(data) == result);
}

SCENARIO("To ascending order for vector whom isn't take ascending order")
{
	std::vector<double> data = { 5.0, 1.0, 2.0 };
	std::vector<double> result = { 1.0, 2.0, 5.0 };
	REQUIRE(ToAscendingOrder(data) == result);
}