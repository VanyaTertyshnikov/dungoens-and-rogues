#ifndef REGULARWEAPON_HPP
#define REGULARWEAPON_HPP

#include "Equation.hpp"
#include "Object.hpp"
#include "Parameter.hpp"
#include "Weapon.hpp"

#include <set>

class RegularWeapon : public Object, Weapon {
public:
  explicit RegularWeapon(std::string name) : Object(name) {}
  RegularWeapon(std::string name, std::string target_param,
                std::set<Equation> equations)
      : Object(name, target_param, equations) {}
  ~RegularWeapon() override;

  std::set<Parameter> compute_damage(std::set<Parameter> params) override;
};

#endif
