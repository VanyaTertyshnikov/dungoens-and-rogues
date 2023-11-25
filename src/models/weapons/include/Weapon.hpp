#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "Parameter.hpp"
#include <set>

class Weapon {
public:
  virtual std::set<Parameter> compute_damage(std::set<Parameter> params) = 0;
};

#endif
