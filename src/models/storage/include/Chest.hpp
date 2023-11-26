#ifndef CHEST_HPP
#define CHEST_HPP

#include "Resistable.hpp"
#include "Storage.hpp"

class Chest : public Storage, Resistable {
private:
  unsigned int level_ = 1;

public:
  Chest(float x, float y, std::string name, std::shared_ptr<Object> inner_obj,
        unsigned int level);

  unsigned int get_level() const;
  void set_level(unsigned int level);

  unsigned int resist() override;
};

#endif
