#include "Artifact.hpp"
#include "Equation.hpp"
#include "Parameter.hpp"
#include <set>
#include <stdexcept>

Artifact::Artifact(std::set<Equation> modifiers) {
  this->modifiers_ = modifiers;
}

std::set<Equation> Artifact::get_modifiers() const { return this->modifiers_; }

void Artifact::set_modifiers(std::set<Equation> modifiers) {
  if (modifiers.empty())
    throw std::invalid_argument("Gotten bunch can not be set as Artifact "
                                "modifiers, has not any data inside.");
  this->modifiers_ = modifiers;
}

std::set<Parameter> Artifact::modify_params(std::set<Parameter> params) {
  std::set<Parameter> result = {};
  for (auto mod : this->modifiers_) {
    Parameter modified_param = mod(params);
    result.insert(modified_param);
  }
  return result;
}
