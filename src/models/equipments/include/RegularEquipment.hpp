#ifndef REGULAREQUIPMENT_HPP
#define REGULAREQUIPMENT_HPP

#include "Equipment.hpp"
#include "Object.hpp"
#include "Parameter.hpp"
class RegularEquipment : public Equipment, Object {
public:
  explicit RegularEquipment(std::string name) : Object(name) {}
  RegularEquipment(std::string name, std::string target_param,
                   std::set<Equation> equaitons, std::string placement)
      : Object(name, target_param, equaitons), Equipment(placement) {}

  ~RegularEquipment() override;

  std::set<Parameter> compute_defence(std::set<Parameter> params) override;
};

#endif
