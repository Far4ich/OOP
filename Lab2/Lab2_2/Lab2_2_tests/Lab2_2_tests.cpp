#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../Catch/catch.hpp"
#include "../Lab2_2/FindAndReplace.h"

SCENARIO("Replacing a substring in a string")
{
	std::string subject = "hi my name is Ahiles";
	std::string search = "hi";
	std::string replace = "hello";
	std::string result = "hello my name is Ahelloles";

	REQUIRE(FindAndReplace(subject, search, replace) == result);
}

SCENARIO("Replacing a substring in a empty string")
{
	std::string subject = "";
	std::string search = "hi";
	std::string replace = "hello";
	std::string result = "";

	REQUIRE(FindAndReplace(subject, search, replace) == result);
}

SCENARIO("Replacing a substring with a string containing two substrings")
{
	std::string subject = "hi my name is Ahiles";
	std::string search = "hi";
	std::string replace = "hihi";
	std::string result = "hihi my name is Ahihiles";

	REQUIRE(FindAndReplace(subject, search, replace) == result);
}

SCENARIO("test test")
{
	std::string subject = "hhii";
	std::string search = "hi";
	std::string replace = "";
	std::string result = "hi";

	REQUIRE(FindAndReplace(subject, search, replace) == result);
}