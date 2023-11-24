#ifndef RELATION_HPP
#define RELATION_HPP

#include "Parameter.hpp"
#include <set>
#include <string>

class Relation {
private:
  std::string target_dimension_ = "";
  unsigned int value_ = 1;

public:
  Relation() = default;
  explicit Relation(std::string target_dimension);
  Relation(std::string target_dimension, unsigned int value);

  std::string get_target_dimension() const;
  void set_target_dimension(std::string target_dimension);

  unsigned int get_value() const;
  void set_value(unsigned int value);

  bool operator<(const Relation &other) const;
  bool operator<=(const Relation &other) const;
  bool operator>(const Relation &other) const;
  bool operator>=(const Relation &other) const;
  bool operator==(const Relation &other) const;
  bool operator!=(const Relation &other) const;

  unsigned int operator()(std::set<Parameter> params);
};

#endif
