//
//  main.cpp
//  str
//
//  Created by Justin Godesky on 11/13/15.
//
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../str.h"
using namespace jgod;

TEST_CASE("position")
{
  SECTION("indexOf")
  {
    SECTION("empty strings returns -1") {REQUIRE(str::indexOf("", "search") == -1);}
    SECTION("empty substrings returns -1") {REQUIRE(str::indexOf("mystring", "") == -1);}
    SECTION("substrings longer than string return -1") {REQUIRE(str::indexOf("str", "string") == -1);}
    SECTION("not found returns -1") {REQUIRE(str::indexOf("mystring", "pizza") == -1);}
    SECTION("found returns index") {REQUIRE(str::indexOf("pizza pie", "pie") == 6);}
  }
  SECTION("startsWith")
  {
    SECTION("does") {REQUIRE(str::startsWith("catdog", "cat"));}
    SECTION("doesn't") {REQUIRE(!str::startsWith("dog", "cat"));}
  }
  SECTION("endsWith")
  {
    SECTION("does") {REQUIRE(str::endsWith("catdog", "dog"));}
    SECTION("doesn't") {REQUIRE(!str::endsWith("cat", "dog"));}
  }
}

TEST_CASE("casing")
{
  const auto SRC = "xx420xNoScOpe$";
  SECTION("to uppercase") {REQUIRE(str::toUpperCase(SRC) == "XX420XNOSCOPE$");}
  SECTION("to lowercase") {REQUIRE(str::toLowerCase(SRC) == "xx420xnoscope$");}
}

TEST_CASE("trimming")
{
  const auto SRC = "  mystring ";
  SECTION("left") {REQUIRE(str::trimLeft(SRC) == "mystring ");}
  SECTION("right")
  {
    SECTION("basic") {REQUIRE(str::trimRight(SRC) == "  mystring");}
    SECTION("delimiter") {REQUIRE(str::trimRight(SRC, "i") == "  mystr");}
  }
  SECTION("remove whitespace") {REQUIRE(str::removeWhitespace(SRC) == "mystring");}
}

TEST_CASE("splitting")
{
  const std::vector<std::string> RESULT = {"abcde", "fghi"};
  SECTION("based on line length") {REQUIRE(str::split("abcdefghi", 5) == RESULT);}
  SECTION("based on delimiter") {REQUIRE(str::split("abcde/fghi", '/') == RESULT);}
}

TEST_CASE("replacement")
{
  const auto SRC = "To be or not to be?";

  SECTION("all occurences with character")
  {
    REQUIRE(str::replace(SRC, "t", "b") == "To be or nob bo be?");
  }
  SECTION("all occurences with string")
  {
    REQUIRE(str::replace(SRC, "be", "test") == "To test or not to test?");
  }
  SECTION("all slashes")
  {
    REQUIRE(str::replaceSlashes("This/is/a/test", ' ') == "This is a test");
  }
  SECTION("all spaces")
  {
    REQUIRE(str::replaceSpaces(SRC, '+') == "To+be+or+not+to+be?");
  }
  SECTION("truncate")
  {
    REQUIRE(str::truncate(SRC, 8, "...") == "To be or...");
  }
}