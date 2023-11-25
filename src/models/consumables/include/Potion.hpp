#ifndef POTION_HPP
#define POTION_HPP

#include "Consumable.hpp"
#include "Equation.hpp"
#include "Object.hpp"
#include "Parameter.hpp"
class Potion : public Object, Consumable {
public:
  explicit Potion(std::string name) : Object(name) {}
  Potion(std::string name, std::string target_param,
         std::set<Equation> equations)
      : Object(name, target_param, equations) {}
  ~Potion() override;

  Parameter compute_use(std::set<Parameter> params) override;
};

#endif
