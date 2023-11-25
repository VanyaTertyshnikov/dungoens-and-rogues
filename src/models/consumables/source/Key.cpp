#include "Key.hpp"
#include "Parameter.hpp"

Parameter Key::compute_use(std::set<Parameter> params) {
  Parameter result{};

  for (auto eq : this->equations_) {
    result = eq(params);
  }

  return result;
}
