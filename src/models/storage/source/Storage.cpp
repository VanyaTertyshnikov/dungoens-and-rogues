#include "Storage.hpp"
#include "Placeable.hpp"
#include <memory>
#include <stdexcept>

Storage::Storage(float x, float y, std::string name,
                 std::shared_ptr<Object> inner_object)
    : Placeable(x, y) {
  this->set_name(name);
  this->set_inner_obj(inner_object);
}

std::string Storage::get_name() const { return this->name_; }

void Storage::set_name(std::string name) {
  if (name.empty())
    throw std::invalid_argument("Name of Storage is empty.");
  this->name_ = name;
}

std::shared_ptr<Object> Storage::get_inner_obj() const {
  return this->inner_obj_;
}

void Storage::set_inner_obj(std::shared_ptr<Object> inner_obj) {
  this->inner_obj_ = inner_obj;
}
