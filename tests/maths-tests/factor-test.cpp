#define CATCH_CONFIG_MAIN

#include "Factor.hpp"
#include <catch2/catch.hpp>

TEST_CASE("FactorPairConstructor") {
  SECTION("Default") {
    FactorPair fp{};
    REQUIRE(fp.get_target_trait() == "");
    REQUIRE(fp.get_vaue() == 1);
  }
  SECTION("Full") {
    FactorPair fp{"Human", 3};
    REQUIRE(fp.get_target_trait() == "Human");
    REQUIRE(fp.get_vaue() == 3);
  }
  SECTION("Exceptions") { REQUIRE_THROWS(FactorPair{"", 0.11}); }
}

TEST_CASE("FactorPairMethods") {
  SECTION("Setters") {
    FactorPair fp;
    fp.set_target_trait("Human");
    REQUIRE(fp.get_target_trait() == "Human");

    fp.set_value(0.11);
    float a = 0.11;
    REQUIRE(fp.get_vaue() == a);
  }
  SECTION("SettersExceptions") {
    FactorPair fp;
    REQUIRE_THROWS(fp.set_target_trait(""));
  }
}

TEST_CASE("FactorConstructor") {
  SECTION("Default") {
    Factor f{};
    REQUIRE(f.get_name() == "");
    FactorPair b{}, w{};
    REQUIRE(f.get_best().get_target_trait() == b.get_target_trait());
    REQUIRE(f.get_worst().get_target_trait() == w.get_target_trait());
  }
  SECTION("NameOnly") {
    Factor f{"Plague"};
    REQUIRE(f.get_name() == "Plague");
    FactorPair b{}, w{};
    REQUIRE(f.get_best().get_target_trait() == b.get_target_trait());
    REQUIRE(f.get_worst().get_target_trait() == w.get_target_trait());
  }
  SECTION("Full") {
    Factor f{"Plugue", {"Human", 2}, {"Undead", 0.5}};
    REQUIRE(f.get_name() == "Plugue");
    REQUIRE(f.get_best().get_target_trait() == "Human");
    REQUIRE(f.get_best().get_vaue() == 2);
    REQUIRE(f.get_worst().get_target_trait() == "Undead");
    REQUIRE(f.get_worst().get_vaue() == 0.5);
  }
  SECTION("Exceptions") {
    REQUIRE_THROWS(Factor{""});
    REQUIRE_THROWS(Factor{"Plague", {"", 2}, {"Undead", 6}});
    REQUIRE_THROWS(Factor{"Plague", {"Human", 2}, {"", 6}});
  }
}

TEST_CASE("FactorMethods") {
  SECTION("Setters") {
    Factor f{};
    f.set_name("Plague");
    REQUIRE(f.get_name() == "Plague");

    f.set_best("Human", 2);
    REQUIRE(f.get_best().get_target_trait() == "Human");
    REQUIRE(f.get_best().get_vaue() == 2);

    f.set_worst("Undead", 0.5);
    REQUIRE(f.get_worst().get_target_trait() == "Undead");
    REQUIRE(f.get_worst().get_vaue() == 0.5);
  }
  SECTION("SettersExceptions") {
    Factor f{};
    REQUIRE_THROWS(f.set_name(""));
    REQUIRE_THROWS(f.set_best("", 2));
    REQUIRE_THROWS(f.set_worst("", 0.5));
  }
}

TEST_CASE("FactorOverloads") {
  Factor f{"Plague", {"Human", 2}, {"Undead", 0.5}};
  REQUIRE(f("Human") == 2);
  REQUIRE(f("Undead") == 0.5);
  REQUIRE(f("Elf") == 1);
}
