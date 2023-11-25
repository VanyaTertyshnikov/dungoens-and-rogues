#include "RegularEquipment.hpp"
#include "Parameter.hpp"

std::set<Parameter>
RegularEquipment::compute_defence(std::set<Parameter> params) {
  std::set<Parameter> result = {};

  for (auto eq : this->equations_) {
    Parameter new_param = eq(params);
    result.insert(new_param);
  }

  return result;
}
