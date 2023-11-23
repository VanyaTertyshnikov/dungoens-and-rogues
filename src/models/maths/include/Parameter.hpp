#ifndef PARAMETER_HPP
#define PARAMETER_HPP

#include <string>

#include <nlohmann/json.hpp>

class Parameter {
private:
  std::string dimension_ = "";
  unsigned int value_ = 0;

public:
  Parameter() = default;
  explicit Parameter(std::string dimension);
  Parameter(std::string dimension, unsigned int value);

  std::string get_dimension() const;
  void set_dimension(std::string dimension);

  unsigned int get_value() const;
  void set_value(unsigned int value);

  bool operator<(const Parameter &other) const;
  bool operator<=(const Parameter &other) const;
  bool operator>(const Parameter &other) const;
  bool operator>=(const Parameter &other) const;
  bool operator==(const Parameter &other) const;
  bool operator!=(const Parameter &other) const;

  Parameter operator+(const Parameter &other) const;
  Parameter operator-(const Parameter &other) const;

  void load(nlohmann::json data);
  nlohmann::json save() const;
};

#endif
