#include "Enchanted.hpp"
#include "Factor.hpp"
#include <stdexcept>

Enchanted::Enchanted(std::set<Factor> factors) { this->set_factors(factors); }

std::set<Factor> Enchanted::get_factors() const { return this->factors_; }

void Enchanted::set_factors(std::set<Factor> factors) {
  if (factors.empty())
    throw std::invalid_argument("Gotten bunch can not be set as Enchanted "
                                "factors, has not any data inside.");
  this->factors_ = factors;
}

float Enchanted::get_factor_value(std::string trait) {
  float max_factor_value = -10000;
  float factor_value = 0;
  for (auto factor : this->factors_) {
    factor_value = factor(trait);
    if (factor_value > max_factor_value)
      max_factor_value = factor_value;
  }
  return max_factor_value;
}
