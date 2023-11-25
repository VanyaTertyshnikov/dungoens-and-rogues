#ifndef CONSUMABLE_HPP
#define CONSUMABLE_HPP

#include "Parameter.hpp"
#include <set>

class Consumable {
public:
  virtual Parameter compute_use(std::set<Parameter> params) = 0;
};

#endif
