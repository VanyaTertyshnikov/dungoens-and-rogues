#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP

#include "Parameter.hpp"
#include <set>

class Equipment {
protected:
  std::string placement_;

public:
  Equipment() = default;
  explicit Equipment(std::string placement);
  virtual ~Equipment();

  std::string get_placement() const { return this->placement_; }
  void set_placement(std::string placement);

  virtual std::set<Parameter> compute_defence(std::set<Parameter> params) = 0;
};

#endif
