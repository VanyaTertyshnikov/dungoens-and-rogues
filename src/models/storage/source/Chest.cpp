#include "Chest.hpp"
#include "Object.hpp"
#include <memory>

Chest::Chest(float x, float y, std::string name,
             std::shared_ptr<Object> inner_obj, unsigned int level)
    : Storage(x, y, name, inner_obj) {
  this->level_ = level;
}

unsigned int Chest::get_level() const { return this->level_; }

void Chest::set_level(unsigned int level) { this->level_ = level; }
