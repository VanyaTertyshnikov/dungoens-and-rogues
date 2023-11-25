#ifndef MIXEDWEAPON_HPP
#define MIXEDWEAPON_HPP

#include "Artifact.hpp"
#include "Enchanted.hpp"
#include "Equation.hpp"
#include "Factor.hpp"
#include "Object.hpp"
#include "Parameter.hpp"
#include "Weapon.hpp"
class MixedWeapon : public Weapon, Object, Artifact, Enchanted {
public:
  explicit MixedWeapon(std::string name) : Object(name) {}
  MixedWeapon(std::string name, std::string target_param,
              std::set<Equation> equations, std::set<Equation> modifiers,
              std::set<Factor> factors)
      : Object(name, target_param, equations), Artifact(modifiers),
        Enchanted(factors) {}
  ~MixedWeapon() override;

  std::set<Parameter> compute_damage(std::set<Parameter> params) override;
};

#endif
