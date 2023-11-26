#include "Placeable.hpp"

Placeable::Placeable(float x, float y) {
  this->x_ = x;
  this->y_ = y;
}

float Placeable::get_x() const { return this->x_; }

void Placeable::set_x(float x) { this->x_ = x; }

float Placeable::get_y() const { return this->y_; }

void Placeable::set_y(float y) { this->y_ = y; }
