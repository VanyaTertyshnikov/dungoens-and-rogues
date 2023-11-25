#ifndef ARTIFACTWEAPON_HPP
#define ARTIFACTWEAPON_HPP

#include "Artifact.hpp"
#include "Equation.hpp"
#include "Object.hpp"
#include "Parameter.hpp"
#include "Weapon.hpp"

class ArtifactWeapon : public Weapon, Object, Artifact {
public:
  explicit ArtifactWeapon(std::string name) : Object(name) {}
  ArtifactWeapon(std::string name, std::string target_param,
                 std::set<Equation> equations, std::set<Equation> modifiers)
      : Object(name, target_param, equations), Artifact(modifiers) {}
  ~ArtifactWeapon() override;

  std::set<Parameter> compute_damage(std::set<Parameter> params) override;
};

#endif
