#ifndef PARAMETER_HPP
#define PARAMETER_HPP

#include <string>

#include <nlohmann/json.hpp>

class Parameter {
private:
  std::string dimension_ = "";
  unsigned int value_ = 0;

public:
  /**
   * @breif Default constructor that set dimension as empty string and value as
   * zero.
   * */
  Parameter() = default;

  /**
   * @breif Constructor which sets dimension by gotten string and value as zero.
   * @param[in] dimension Gotten string which should be set as dimension.
   * @throws std::invalid_argument If gotten string is empty.
   * */
  explicit Parameter(std::string dimension);

  /**
   * @brief Constructor which sets dimension by gotten string and value by
   * gotten unsigned integer
   * @param[in] dimension Gotten string which should be set as dimension.
   * @param[in] value Gotten unsigned integer which should be set as value.
   * @throws std::invalid_argument If gotten string is empty
   * */
  Parameter(std::string dimension, unsigned int value);

  /**
   * @brief Method whick returns dimension of this instance.
   * @returns Dimension of instance.
   * */
  std::string get_dimension() const;

  /**
   * @breif Method which sets gotten string as dimension of instance.
   * @param[in] dimension Gotten string which should be set as dimension.
   * @throws std::invalid_argument If gotten string is empty.
   * */
  void set_dimension(std::string dimension);

  /**
   * @brief Method which returns value of this instance.
   * @returns Value of instance.
   * */
  unsigned int get_value() const;

  /**
   * @brief Method which sets gotten unsigned integer as value of instance.
   * @param[in] value Gotten unsigned integer which should be set as value of
   * instance.
   * */
  void set_value(unsigned int value);

  /**
   * @brief Overloaded operator <
   *
   * Compare two instances by thier dimensions as strings
   * */
  bool operator<(const Parameter &other) const;

  /**
   * @brief Overloaded operator ==
   *
   * Compare two instances by their dimensions as strings
   * */
  bool operator==(const Parameter &other) const;

  /**
   * @brief Overloaded operator +
   *
   * Summarize to instances with same dimensions.
   * @throws std::invalid_argument If one of instances has an empty dimension.
   * @throws std::logic_error If instances have different dimensions.
   * */
  Parameter operator+(const Parameter &other) const;

  /**
   * @brief Overloaded operator -
   *
   * Compute difference between instances.
   * @throws std::invalid_argument If one of instances has an empty dimension
   * @throws std::logic_error If instances have different dimensions.
   * */
  Parameter operator-(const Parameter &other) const;

  /**
   * @breif Method which provides loading from JSON object.
   *
   * Required that JSON object has "dimension" field and "value" field.
   * @param[in] data JSON object
   * */
  void load(nlohmann::json data);

  /**
   * @brief Method which provides saving instance to JSON object.
   *
   * @returns JSON object with "dimension" field and "value" field
   * */
  nlohmann::json save() const;
};

#endif
