#ifndef EQUATION_HPP
#define EQUATION_HPP

#include "Parameter.hpp"
#include "Relation.hpp"
#include <set>
#include <string>

class Equation {
private:
  std::string target_param_ = "";
  std::set<Relation> relations_ = {};
  unsigned int base_ = 0;

public:
  Equation() = default;
  explicit Equation(std::string target_param);
  Equation(std::string target_param, std::set<Relation> relations);
  Equation(std::string target_param, std::set<Relation> relations,
           unsigned int base);

  std::string get_target_param() const;
  void set_target_param(std::string target_param);

  std::set<Relation> get_relations() const;
  void set_relations(std::set<Relation> relations);

  unsigned int get_base() const;
  void set_base(unsigned int base);

  bool operator<(const Equation &other) const;
  bool operator==(const Equation &other) const;

  Parameter operator()(std::set<Parameter> params);
};

#endif
