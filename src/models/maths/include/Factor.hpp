#ifndef FACTOR_HPP
#define FACTOR_HPP

#include <string>

class FactorPair {
private:
  std::string target_trait_ = "";
  float value_ = 1;

public:
  FactorPair() = default;
  FactorPair(std::string target_triat, float value);

  std::string get_target_trait() const;
  void set_target_trait(std::string target_triat);

  float get_vaue() const;
  void set_value(float value);
};

class Factor {
private:
  std::string name_ = "";
  FactorPair best_{};
  FactorPair worst_{};

public:
  Factor() = default;
  explicit Factor(std::string name);
  Factor(std::string name, FactorPair best, FactorPair worst);

  std::string get_name() const;
  void set_name(std::string name);

  FactorPair get_best() const;
  void set_best(std::string target_triat, float value);

  FactorPair get_worst() const;
  void set_worst(std::string target_triat, float value);

  bool operator<(const Factor &other) const;
  bool operator==(const Factor &other) const;

  float operator()(std::string trait);
};

#endif
