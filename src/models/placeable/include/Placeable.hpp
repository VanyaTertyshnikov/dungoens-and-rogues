#ifndef PLACEABLE_HPP
#define PLACEABLE_HPP

class Placeable {
protected:
  float x_;
  float y_;

public:
  Placeable() = default;
  Placeable(float x, float y);

  float get_x() const;
  void set_x(float x);

  float get_y() const;
  void set_y(float y);
};

#endif
