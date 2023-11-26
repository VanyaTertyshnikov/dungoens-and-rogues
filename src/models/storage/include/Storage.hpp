#ifndef STORAGE_HPP
#define STORAGE_HPP

#include "Object.hpp"
#include "Placeable.hpp"
#include <algorithm>
#include <memory>
#include <string>

class Storage : public Placeable {
protected:
  std::string name_;
  std::shared_ptr<Object> inner_obj_;

public:
  Storage(float x, float y, std::string name,
          std::shared_ptr<Object> inner_obj);

  std::string get_name() const;
  void set_name(std::string name);

  std::shared_ptr<Object> get_inner_obj() const;
  void set_inner_obj(std::shared_ptr<Object> inner_obj);
};

#endif
