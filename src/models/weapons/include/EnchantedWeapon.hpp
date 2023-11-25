#ifndef ENCHANTEDWEAPON_HPP
#define ENCHANTEDWEAPON_HPP

#include "Enchanted.hpp"
#include "Equation.hpp"
#include "Factor.hpp"
#include "Object.hpp"
#include "Parameter.hpp"
#include "Weapon.hpp"
class EnchantedWeapon : public Weapon, Object, Enchanted {
public:
  explicit EnchantedWeapon(std::string name) : Object(name) {}
  EnchantedWeapon(std::string name, std::string target_param,
                  std::set<Equation> equations, std::set<Factor> factors)
      : Object(name, target_param, equations), Enchanted(factors) {}
  ~EnchantedWeapon() override;

  std::set<Parameter> compute_damage(std::set<Parameter> params) override;
};

#endif
