#ifndef ENCHANTED_HPP
#define ENCHANTED_HPP

#include "Factor.hpp"
#include <set>

class Enchanted {
protected:
  std::set<Factor> factors_;

public:
  Enchanted() = default;
  explicit Enchanted(std::set<Factor> factors);
  virtual ~Enchanted();

  std::set<Factor> get_factors() const;
  void set_factors(std::set<Factor> factors);

  float get_factor_value(std::string trait);
};

#endif
