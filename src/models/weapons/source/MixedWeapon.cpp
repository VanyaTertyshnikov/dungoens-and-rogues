#include "MixedWeapon.hpp"
#include "Parameter.hpp"

std::set<Parameter> MixedWeapon::compute_damage(std::set<Parameter> params) {
  std::set<Parameter> result = {};

  params = modify_params(params);
  for (auto eq : this->equations_) {
    Parameter new_param = eq(params);
    result.insert(new_param);
  }

  return result;
}
