#include "Relation.hpp"
#include "Parameter.hpp"
#include <set>
#include <stdexcept>

Relation::Relation(std::string target_dimension) {
  this->set_target_dimension(target_dimension);
}

Relation::Relation(std::string target_dimension, unsigned int value)
    : Relation(target_dimension) {
  this->set_value(value);
}

std::string Relation::get_target_dimension() const {
  return this->target_dimension_;
}

void Relation::set_target_dimension(std::string target_dimension) {
  if (target_dimension.empty())
    throw std::invalid_argument("Gotten string can not be set as target "
                                "dimension, has not any dta iniside.");
  this->target_dimension_ = target_dimension;
}

unsigned int Relation::get_value() const { return this->value_; }

void Relation::set_value(unsigned int value) {
  if (value == 0)
    value = 1;
  this->value_ = value;
}

bool Relation::operator<(const Relation &other) const {
  return this->target_dimension_ < other.target_dimension_;
}

bool Relation::operator==(const Relation &other) const {
  return this->target_dimension_ == other.target_dimension_;
}

unsigned int Relation::operator()(std::set<Parameter> params) {
  unsigned int result = 0;

  for (auto &param : params) {
    if (param.get_dimension() == this->target_dimension_) {
      result = param.get_value() / this->value_;
      break;
    }
  }

  return result;
}
