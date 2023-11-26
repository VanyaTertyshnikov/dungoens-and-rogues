#include "Parameter.hpp"
#include <set>
#define CATCH_CONFIG_MAIN

#include "Relation.hpp"
#include <catch2/catch.hpp>

TEST_CASE("Constructor") {
  SECTION("Default") {
    Relation rel{};
    REQUIRE(rel.get_target_dimension() == "");
    REQUIRE(rel.get_value() == 1);
  }
  SECTION("TargetDimensionOnly") {
    Relation rel{"Power"};
    REQUIRE(rel.get_target_dimension() == "Power");
    REQUIRE(rel.get_value() == 1);
  }
  SECTION("Full") {
    Relation rel{"Power", 5};
    REQUIRE(rel.get_target_dimension() == "Power");
    REQUIRE(rel.get_value() == 5);
  }
  SECTION("Exceptions") {
    REQUIRE_THROWS(Relation{""});
    REQUIRE_THROWS(Relation{"", 5});
  }
}

TEST_CASE("Methods") {
  SECTION("Setters") {
    Relation rel{};
    rel.set_target_dimension("Power");
    REQUIRE(rel.get_target_dimension() == "Power");

    rel.set_value(5);
    REQUIRE(rel.get_value() == 5);
  }
  SECTION("SettersExceptions") {
    Relation rel;
    REQUIRE_THROWS(rel.set_target_dimension(""));
  }
}

TEST_CASE("Overloads") {
  SECTION("Functor") {
    std::set<Parameter> params = {{"Power", 10},
                                  {"Agibility", 10},
                                  {"Endurance", 10},
                                  {"Health", 100},
                                  {"HealthLimit", 100}};
    Relation rel1{"Power", 5};
    unsigned int res1 = rel1(params);
    REQUIRE(res1 == 2);

    Relation rel2{"Agibility", 2};
    unsigned int res2 = rel2(params);
    REQUIRE(res2 == 5);
  }
}
