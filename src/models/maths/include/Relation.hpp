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
  /**
   * @brief default constructor which sets target_dimension as empty string and
   * value as 1.
   * */
  Relation() = default;

  /**
   * @brief constructor which sets target_dimension as gotten string and value
   * as 1.
   * @param[in] target_dimension Gotten string which should be set as
   * target_dimension
   * */
  explicit Relation(std::string target_dimension);

  /**
   * @brief constructor which sets target_dimension as gotten string and value
   * as gotten unsigned integer.
   *
   * @param[in] target_dimension Gotten stirng which should be set as
   * target_dimension
   * @param[in] value Gotten unsigned integer which shoud be set as value.
   * */
  Relation(std::string target_dimension, unsigned int value);

  /**
   * @brief Method which returns target dimension.
   * @returns Target dimenison
   * */
  std::string get_target_dimension() const;

  /**
   * @brief Method which sets target dimension by gotten string
   * @param[in] target_dimension Gotten string which should be set as target
   * dimension.
   * @throws std::invalid_argument If Gotten string is empty.
   * */
  void set_target_dimension(std::string target_dimension);

  /**
   * @brief Method which returns value.
   * @returns Value of Relation.
   * */
  unsigned int get_value() const;

  /**
   * @brief Method which sets value by gotten unsigned integer.
   * @param[in] value Gotten unsigned integer which should be set as value
   * */
  void set_value(unsigned int value);

  /**
   * @brief Overloaded operator <
   *
   * Compare by target dimension as strings
   * */
  bool operator<(const Relation &other) const;
  /**
   * @brief Overloaded operator ==
   *
   * Compare by target dimension as strings
   * */
  bool operator==(const Relation &other) const;

  /**
   * @brief Overloaded operator ()
   *
   * Compute result as relation betweeem gotten Paremeter and its relation
   * value.
   * @return result of computing
   * */
  unsigned int operator()(std::set<Parameter> params);
};

#endif
