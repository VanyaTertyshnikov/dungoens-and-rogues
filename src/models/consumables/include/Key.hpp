#ifndef KEY_HPP
#define KEY_HPP

#include "Consumable.hpp"
#include "Equation.hpp"
#include "Object.hpp"
#include "Parameter.hpp"
class Key : public Object, Consumable {
public:
  explicit Key(std::string name) : Object(name){};
  Key(std::string name, std::string target_param, std::set<Equation> equations)
      : Object(name, target_param, equations){};
  ~Key() override;

  Parameter compute_use(std::set<Parameter> params) override;
};

#endif
