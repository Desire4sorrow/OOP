
#include <iostream>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "C:/Users/Андрей/source/repos/catch2/catch.hpp"
#include "../HTMLDecode/Decoder.h"

using namespace std;

TEST_CASE("Decode empty string")
{
	string str = "";
	string test = DecodeHtml(str);
	string expectedStr = "";
	REQUIRE(test == expectedStr);
}

TEST_CASE("Decode string with html entities")
{
	string str = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	string test = DecodeHtml(str);
	string expectedStr = "Cat <says> \"Meow\". M&M\'s";
	REQUIRE(test == expectedStr);
}

TEST_CASE("Decode string without html entities")
{
	string str = "String without html entities";
	string test = DecodeHtml(str);
	string expectedStr = "String without html entities";
	REQUIRE(test == expectedStr);
}