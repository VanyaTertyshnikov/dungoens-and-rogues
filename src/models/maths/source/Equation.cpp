#include "Parameter.hpp"
#include "Relation.hpp"
#include <Equation.hpp>
#include <stdexcept>

#include <set>

Equation::Equation(std::string target_param) {
  this->set_target_param(target_param);
}

Equation::Equation(std::string target_param, std::set<Relation> relations)
    : Equation(target_param) {
  this->set_relations(relations);
}

Equation::Equation(std::string target_param, std::set<Relation> relations,
                   unsigned int base)
    : Equation(target_param, relations) {
  this->set_base(base);
}

std::string Equation::get_target_param() const { return this->target_param_; }

void Equation::set_target_param(std::string target_param) {
  if (target_param.empty())
    throw std::invalid_argument(
        "Gotten string can not be set as target parameter of Equation, has not "
        "any data inside.");
  this->target_param_ = target_param;
}

std::set<Relation> Equation::get_relations() const { return this->relations_; }

void Equation::set_relations(std::set<Relation> relations) {
  if (relations.empty())
    throw std::invalid_argument("Gotten miltitude can not be set as relations "
                                "of Equation, has not any data inside.");
  this->relations_ = relations;
}

unsigned int Equation::get_base() const { return this->base_; }

void Equation::set_base(unsigned int base) { this->base_ = base; }

bool Equation::operator<(const Equation &other) const {
  return this->target_param_ < other.target_param_;
}

bool Equation::operator<=(const Equation &other) const {
  return this->target_param_ <= other.target_param_;
}

bool Equation::operator>(const Equation &other) const {
  return this->target_param_ > other.target_param_;
}

bool Equation::operator>=(const Equation &other) const {
  return this->target_param_ >= other.target_param_;
}

bool Equation::operator==(const Equation &other) const {
  return this->target_param_ == other.target_param_;
}

bool Equation::operator!=(const Equation &other) const {
  return this->target_param_ != other.target_param_;
}

Parameter Equation::operator()(std::set<Parameter> params) {
  unsigned int result_of_equation = this->base_;
  for (auto rel : this->relations_) {
    result_of_equation += rel(params);
  }
  return Parameter{this->target_param_, result_of_equation};
}
