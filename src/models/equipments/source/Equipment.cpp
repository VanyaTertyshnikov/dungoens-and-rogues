#include "Equipment.hpp"
#include <stdexcept>

Equipment::Equipment(std::string placement) { this->set_placement(placement); }

void Equipment::set_placement(std::string placement) {
  if (placement.empty())
    throw std::invalid_argument("Gotten string ca not be set as placement of "
                                "Equipment, has not any data inside.");
  this->placement_ = placement;
}
