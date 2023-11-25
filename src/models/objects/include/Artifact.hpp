#ifndef ARTIFACT_HPP
#define ARTIFACT_HPP

#include "Equation.hpp"
#include "Parameter.hpp"
#include <set>
class Artifact {
protected:
  std::set<Equation> modifiers_;

public:
  Artifact() = default;
  explicit Artifact(std::set<Equation> modifiers);
  virtual ~Artifact();

  std::set<Equation> get_modifiers() const;
  void set_modifiers(std::set<Equation> modifiers);

  std::set<Parameter> modify_params(std::set<Parameter> params);
};

#endif
