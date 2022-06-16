#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../../Catch/catch.hpp"
#include "../Lab2_3/AddWords.h"

SCENARIO("Check freq of letters")
{
	std::string subject = "aa aa b b.";
	std::map <std::string, int> testMap;
	AddWords(subject, testMap);

	REQUIRE((testMap["aa"] == 2 && testMap["b"] == 1 && testMap["b."] == 1));
}

SCENARIO("Check freq of empty string")
{
	std::string subject = "";
	std::map <std::string, int> testMap;
	AddWords(subject, testMap);

	REQUIRE(testMap.size() == 0);
}