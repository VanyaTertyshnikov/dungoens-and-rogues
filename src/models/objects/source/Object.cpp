#include "Object.hpp"
#include "Equation.hpp"
#include <stdexcept>

Object::Object(std::string name) { this->set_name(name); }

Object::Object(std::string name, std::string target_param,
               std::set<Equation> equations)
    : Object(name) {
  this->set_target_param(target_param);
  this->set_equations(equations);
}

std::string Object::get_name() const { return this->name_; }

void Object::set_name(std::string name) {
  if (name.empty())
    throw std::invalid_argument("Gotten string can not be set as Object name, "
                                "has not any data inside.");
  this->name_ = name;
}

std::string Object::get_target_param() const { return this->target_param_; }

void Object::set_target_param(std::string target_param) {
  if (target_param.empty())
    throw std::invalid_argument("Gotten string can not be set as Object name, "
                                "has not any data inside.");
  this->target_param_ = target_param;
}

std::set<Equation> Object::get_equations() const { return this->equations_; }

void Object::set_equations(std::set<Equation> equations) {
  if (equations.empty())
    throw std::invalid_argument("Gotten bunch can not be set as Object "
                                "equations, has not anu data inside.");
  this->equations_ = equations;
}
