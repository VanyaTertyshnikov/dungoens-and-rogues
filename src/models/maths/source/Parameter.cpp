#include "Parameter.hpp"
#include <stdexcept>

Parameter::Parameter(std::string dimension) { this->set_dimension(dimension); }

Parameter::Parameter(std::string dimension, unsigned int value)
    : Parameter(dimension) {
  this->set_value(value);
}

std::string Parameter::get_dimension() const { return this->dimension_; }

void Parameter::set_dimension(std::string dimension) {
  if (dimension.empty())
    throw std::invalid_argument("Gotten string can not be set as Parameter "
                                "dimension, has not any data inside.");
  this->dimension_ = dimension;
}

unsigned int Parameter::get_value() const { return this->value_; }

void Parameter::set_value(unsigned int value) { this->value_ = value; }

bool Parameter::operator<(const Parameter &other) const {
  return this->dimension_ < other.dimension_;
}

bool Parameter::operator<=(const Parameter &other) const {
  return this->dimension_ <= other.dimension_;
}

bool Parameter::operator>(const Parameter &other) const {
  return this->dimension_ > other.dimension_;
}

bool Parameter::operator>=(const Parameter &other) const {
  return this->dimension_ >= other.dimension_;
}

bool Parameter::operator==(const Parameter &other) const {
  return this->dimension_ == other.dimension_;
}

bool Parameter::operator!=(const Parameter &other) const {
  return this->dimension_ != other.dimension_;
}

Parameter Parameter::operator+(const Parameter &other) const {
  if (this->dimension_.empty())
    throw std::invalid_argument(
        "This instance of Parameter has invalid dimension, no data inside.");
  if (other.dimension_.empty())
    throw std::invalid_argument(
        "Other instance of Parameter has invalid dimension, no data inside.");
  if (this->dimension_ != other.dimension_)
    throw std::logic_error(
        "Instances can not be summarize, have different dimensions.");
  return Parameter{this->dimension_, this->value_ + other.value_};
}

Parameter Parameter::operator-(const Parameter &other) const {
  if (this->dimension_.empty())
    throw std::invalid_argument(
        "This instance of Parameter has invalid dimension, no data inside.");
  if (other.dimension_.empty())
    throw std::invalid_argument(
        "Other instance of Parameter has invalid dimension, no data inside.");
  if (this->dimension_ != other.dimension_)
    throw std::logic_error(
        "Instances can not be summarize, have different dimensions.");
  int dif_value = int(this->value_) - int(other.value_);
  if (dif_value < 0)
    dif_value = 0;
  return Parameter{this->dimension_, unsigned(dif_value)};
}

void Parameter::load(nlohmann::json data) {
  this->dimension_ = data["dimension"].get<std::string>();
  this->value_ = data["value"].get<unsigned int>();
}

nlohmann::json Parameter::save() const {
  nlohmann::json data;
  data["dimension"] = this->dimension_;
  data["value"] = this->value_;
  return data;
}
