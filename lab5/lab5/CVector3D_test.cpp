#define CATCH_CONFIG_MAIN
#include "../../Catch/catch.hpp"
#include "CVector3D.h"

SCENARIO("Creating CVector3D test")
{
	CVector3D vectorNull;

	CVector3D vector(1.0, 2.0, 3.0);

	REQUIRE((vectorNull.x == 0 && vectorNull.y == 0 && vectorNull.z == 0));
	REQUIRE((vector.x == 1.0 && vector.y == 2.0 && vector.z == 3.0));
}

SCENARIO("Get length test")
{
	CVector3D vectorNull;

	CVector3D vector(1.0, 1.0, 1.0);

	REQUIRE(vectorNull.GetLength() == 0);
	REQUIRE(vector.GetLength() == sqrt(3));
}

SCENARIO("Operator == test")
{
	CVector3D vectorNull;

	CVector3D vector(1.0, 1.0, 1.0);

	REQUIRE((vectorNull == vectorNull));
	REQUIRE(!(vectorNull == vector));
}

SCENARIO("Operator != test")
{
	CVector3D vectorNull;

	CVector3D vector(1.0, 1.0, 1.0);

	REQUIRE((vectorNull != vector));
	REQUIRE(!(vector != vector));
}

SCENARIO("Normalize test")
{
	CVector3D vectorNull;
	vectorNull.Normalize();

	REQUIRE((vectorNull == vectorNull));

	CVector3D vector(2.0, 2.0, 2.0);
	CVector3D vectorCopy(2.0, 2.0, 2.0);
	vector.Normalize();

	REQUIRE((vector == vectorCopy / vectorCopy.GetLength()));
}

SCENARIO("Dot product test")
{
	CVector3D vectorNull;

	CVector3D vector(2.0, 2.0, 2.0);

	REQUIRE(DotProduct(vectorNull, vector) == 0);
	REQUIRE(DotProduct(vector, vector) == 12);
}

SCENARIO("Cross product test")
{
	CVector3D vectorNull;

	CVector3D vector1(2.0, 2.0, 2.0);
	CVector3D vector2(2.0, 3.0, 4.0);

	REQUIRE((CrossProduct(vectorNull, vector1) == vectorNull));
	REQUIRE((CrossProduct(vector1, vector2) == CVector3D(2, -4, 2)));
}

SCENARIO("Unary operators test")
{
	CVector3D vectorNull;

	REQUIRE((+vectorNull == vectorNull));
	REQUIRE((-vectorNull == vectorNull));

	CVector3D vector(2.0, 2.0, 2.0);

	REQUIRE((+vector == vector));
	REQUIRE((-vector == CVector3D(-2.0, -2.0, -2.0)));
}

SCENARIO("Binary operators test")
{
	CVector3D vectorNull;
	CVector3D vector(2.0, 2.0, 2.0);

	REQUIRE((vector + vector == CVector3D(4, 4, 4)));
	REQUIRE((vector - vector == vectorNull));
	REQUIRE((vector * 2 == CVector3D(4, 4, 4)));
	REQUIRE((2 * vector == CVector3D(4, 4, 4)));
	REQUIRE((vector / 2 == CVector3D(1, 1, 1)));
}

SCENARIO("Assignment expressions test")
{
	CVector3D vectorNull;
	CVector3D vector(2.0, 2.0, 2.0);

	REQUIRE(((CVector3D(1.0, 2.0, 3.0) += vector) == CVector3D(3, 4, 5)));
	REQUIRE(((CVector3D(5.0, 4.0, 3.0) -= vector) == CVector3D(3, 2, 1)));
	REQUIRE(((vector *= 2) == CVector3D(4, 4, 4)));
	REQUIRE(((vector /= 2) == CVector3D(2, 2, 2)));
}

SCENARIO("Input/output test")
{
	CVector3D vectorNull;
	std::stringstream instr;
	
	instr << "1 2 3";
	instr >> vectorNull;
	REQUIRE((vectorNull.x == 1 && vectorNull.y == 2 && vectorNull.z == 3));

	CVector3D vector(2.0, 2.0, 2.0);
	std::ostringstream outstr;

	outstr << vector;
	REQUIRE("2, 2, 2" == outstr.str());
}