#ifndef ARTIFACT_HPP
#define ARTIFACT_HPP

#include "Equation.hpp"
#include "Parameter.hpp"
#include <set>
class Artifact {
private:
  std::set<Equation> modifiers_;

public:
  Artifact() = default;
  explicit Artifact(std::set<Equation> modifiers);

  std::set<Equation> get_modifiers() const;
  void set_modifiers(std::set<Equation> modifiers);

  std::set<Parameter> modify_params(std::set<Parameter> params);
};

#endif
