#include "EnchantedWeapon.hpp"
#include "Parameter.hpp"

std::set<Parameter>
EnchantedWeapon::compute_damage(std::set<Parameter> params) {
  std::set<Parameter> result = {};

  for (auto eq : this->equations_) {
    Parameter new_param = eq(params);
    result.insert(new_param);
  }

  return result;
}
