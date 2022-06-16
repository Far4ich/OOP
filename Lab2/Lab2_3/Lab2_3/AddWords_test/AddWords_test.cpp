// AddWords_test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../../Catch/catch.hpp"
#include "../Lab2_3/AddWords.h"

SCENARIO("Check freq of letters")
{
	string subject = "aa aa b b.";
	map <string, int> testMap;
	AddWords(subject, testMap);

	REQUIRE((testMap["aa"] == 2 && testMap["b"] == 1 && testMap["b."] == 1));
}