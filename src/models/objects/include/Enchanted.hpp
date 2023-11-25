#ifndef ENCHANTED_HPP
#define ENCHANTED_HPP

#include "Factor.hpp"
#include <set>

class Enchanted {
private:
  std::set<Factor> factors_;

public:
  Enchanted() = default;
  explicit Enchanted(std::set<Factor> factors);

  std::set<Factor> get_factors() const;
  void set_factors(std::set<Factor> factors);

  float get_factor_value(std::string trait);
};

#endif
