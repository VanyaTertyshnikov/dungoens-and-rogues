#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Equation.hpp"
#include "Parameter.hpp"
#include <set>
#include <string>

class Object {
protected:
  std::string name_ = "";
  std::string target_param_ = "";
  std::set<Equation> equations = {};

public:
  Object() = default;
  Object(std::string name, std::string target_param,
         std::set<Equation> equations);

  std::string get_name() const;
  void set_name(std::string name);

  std::string get_target_param() const;
  void set_target_param(std::string target_param);

  std::set<Equation> get_equations() const;
  void set_equations(std::set<Equation> equations);
};

#endif
