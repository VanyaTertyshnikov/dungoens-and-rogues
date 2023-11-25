#include "Factor.hpp"
#include <stdexcept>
#include <string>

FactorPair::FactorPair(std::string target_trait, float value) {
  this->set_target_trait(target_trait);
  this->set_value(value);
}

std::string FactorPair::get_target_trait() const { return this->target_trait_; }

void FactorPair::set_target_trait(std::string target_trait) {
  if (target_trait.empty())
    throw std::invalid_argument("Gotten string can not be set as target triat "
                                "of FactorPair, has not any data inside.");
  this->target_trait_ = target_trait;
}

float FactorPair::get_vaue() const { return this->value_; }

void FactorPair::set_value(float value) { this->value_ = value; }

Factor::Factor(std::string name) { this->set_name(name); }

Factor::Factor(std::string name, FactorPair best, FactorPair worst)
    : Factor(name) {
  if (best.get_target_trait().empty())
    throw std::invalid_argument("Gotten FactorPair can not be set as best of "
                                "Factor, invalid target trait.");
  if (worst.get_target_trait().empty())
    throw std::invalid_argument("Gotten FactorPair can not be set as worst of "
                                "Factor, invalid target trait.");
  this->best_ = best;
  this->worst_ = worst;
}

std::string Factor::get_name() const { return this->name_; }

void Factor::set_name(std::string name) {
  if (name.empty())
    throw std::invalid_argument("Gotten string can not be set as name of "
                                "Factor, has not any data inside.");
  this->name_ = name;
}

FactorPair Factor::get_best() const { return this->best_; }

void Factor::set_best(std::string target_trait, float value) {
  this->best_ = FactorPair{target_trait, value};
}

FactorPair Factor::get_worst() const { return this->worst_; }

void Factor::set_worst(std::string target_trait, float value) {
  this->worst_ = FactorPair{target_trait, value};
}

bool Factor::operator<(const Factor &other) const {
  return this->name_ < other.name_;
}

bool Factor::operator<=(const Factor &other) const {
  return this->name_ <= other.name_;
}

bool Factor::operator>(const Factor &other) const {
  return this->name_ > other.name_;
}

bool Factor::operator>=(const Factor &other) const {
  return this->name_ >= other.name_;
}

bool Factor::operator==(const Factor &other) const {
  return this->name_ == other.name_;
}

bool Factor::operator!=(const Factor &other) const {
  return this->name_ != other.name_;
}

float Factor::operator()(std::string trait) {
  float result = 1;
  if (trait == this->best_.get_target_trait())
    result = this->best_.get_vaue();
  else if (trait == this->worst_.get_target_trait())
    result = this->worst_.get_vaue();
  return result;
}
