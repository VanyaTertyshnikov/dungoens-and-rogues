#ifndef ARTIFACTEQUIPMENT_HPP
#define ARTIFACTEQUIPMENT_HPP

#include "Artifact.hpp"
#include "Equation.hpp"
#include "Equipment.hpp"
#include "Object.hpp"
#include "Parameter.hpp"

class ArtifactEquipment : public Equipment, Object, Artifact {
public:
  explicit ArtifactEquipment(std::string name) : Object(name){};
  ArtifactEquipment(std::string name, std::string target_param,
                    std::set<Equation> equations, std::set<Equation> modifiers,
                    std::string placement)
      : Object(name, target_param, equations), Artifact(modifiers),
        Equipment(placement) {}
  ~ArtifactEquipment() override;

  std::set<Parameter> compute_defence(std::set<Parameter> params) override;
};

#endif
