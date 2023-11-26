#include "Relation.hpp"
#define CATCH_CONFIG_MAIN

#include "Parameter.hpp"
#include <catch2/catch.hpp>

TEST_CASE("Conctructor") {
  SECTION("Default") {
    Parameter p{};
    REQUIRE(p.get_dimension() == "");
    REQUIRE(p.get_value() == 0);
  }
  SECTION("DimensionOnly") {
    Parameter p{"Power"};
    REQUIRE(p.get_dimension() == "Power");
    REQUIRE(p.get_value() == 0);
  }
  SECTION("Full") {
    Parameter p{"Power", 10};
    REQUIRE(p.get_dimension() == "Power");
    REQUIRE(p.get_value() == 10);
  }
  SECTION("Exceptions") {
    REQUIRE_THROWS(Parameter{""});
    REQUIRE_THROWS(Parameter{"", 10});
  }
}

TEST_CASE("Methods") {
  SECTION("Setters") {
    Parameter p{};
    p.set_dimension("Power");
    REQUIRE(p.get_dimension() == "Power");

    p.set_value(10);
    REQUIRE(p.get_value() == 10);
  }
  SECTION("SettersExeptions") {
    Parameter p{};
    REQUIRE_THROWS(p.set_dimension(""));
  }
}

TEST_CASE("Overloads") {
  SECTION("Summarize") {
    Parameter p1{"Power", 10}, p2{"Power", 15};
    Parameter p12s = p1 + p2;
    Parameter p12d = p1 - p2;
    Parameter p21s = p2 + p1;
    Parameter p21d = p2 - p1;
    REQUIRE(p12s.get_dimension() == "Power");
    REQUIRE(p12s.get_value() == 25);
    REQUIRE(p12d.get_dimension() == "Power");
    REQUIRE(p12d.get_value() == 0);
    REQUIRE(p21s.get_dimension() == "Power");
    REQUIRE(p21s.get_value() == 25);
    REQUIRE(p21d.get_dimension() == "Power");
    REQUIRE(p21d.get_value() == 5);
  }
  SECTION("SummarizeExceptions") {
    Parameter p1{}, p3{"Power", 10}, p4{"Agibility", 12};
    REQUIRE_THROWS(p1 + p3);
    REQUIRE_THROWS(p3 + p1);
    REQUIRE_THROWS(p3 + p4);
    REQUIRE_THROWS(p1 - p3);
    REQUIRE_THROWS(p3 - p1);
    REQUIRE_THROWS(p3 - p4);
  }
}
