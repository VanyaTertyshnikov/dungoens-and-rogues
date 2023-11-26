#include "Relation.hpp"
#define CATCH_CONFIG_MAIN

#include "Equation.hpp"
#include <catch2/catch.hpp>

TEST_CASE("Constructor") {
  SECTION("Default") {
    Equation eq{};
    REQUIRE(eq.get_target_param() == "");
    REQUIRE(eq.get_relations().empty());
    REQUIRE(eq.get_base() == 0);
  }
  SECTION("TargetParameterOnly") {
    Equation eq{"Power"};
    REQUIRE(eq.get_target_param() == "Power");
    REQUIRE(eq.get_relations().empty());
    REQUIRE(eq.get_base() == 0);
  }
  SECTION("WithoutBase") {
    std::set<Relation> rels = {
        {"Power", 1}, {"Agibility", 3}, {"Endurance", 2}};
    Equation eq{"Power", rels};
    REQUIRE(eq.get_target_param() == "Power");
    REQUIRE(eq.get_relations() == rels);
    REQUIRE(eq.get_base() == 0);
  }
  SECTION("Full") {
    std::set<Relation> rels = {
        {"Power", 1}, {"Agibility", 3}, {"Endurance", 2}};
    Equation eq{"Damage", rels, 10};
    REQUIRE(eq.get_target_param() == "Damage");
    REQUIRE(eq.get_relations() == rels);
    REQUIRE(eq.get_base() == 10);
  }
  SECTION("Ecxeptions") {
    REQUIRE_THROWS(Equation{""});
    REQUIRE_THROWS(Equation{"Damage", {}});
  }
}

TEST_CASE("Methods") {
  SECTION("Setters") {
    Equation eq;
    eq.set_target_param("Damage");
    std::cout << eq.get_target_param() << std::endl;
    REQUIRE(eq.get_target_param() == "Damage");

    std::set<Relation> rels = {
        {"Power", 1}, {"Agibility", 3}, {"Endurance", 2}};

    eq.set_relations(rels);
    REQUIRE(eq.get_relations() == rels);

    eq.set_base(10);
    REQUIRE(eq.get_base() == 10);
  }
  SECTION("SettersExceptions") {
    Equation eq;
    REQUIRE_THROWS(eq.set_target_param(""));
    REQUIRE_THROWS(eq.set_relations({}));
  }
}

TEST_CASE("Overloads") {
  std::set<Parameter> params = {{"Power", 10},
                                {"Agibility", 15},
                                {"Endurance", 5},
                                {"Healt", 100},
                                {"HealtLimit", 100}};
  std::set<Relation> rels = {{"Power", 2}, {"Agibility", 5}, {"Endurance", 1}};
  Equation eq{"Damage", rels, 10};
  Parameter computed_param = eq(params);
  REQUIRE(computed_param.get_dimension() == "Damage");
  REQUIRE(computed_param.get_value() == 23);
}
