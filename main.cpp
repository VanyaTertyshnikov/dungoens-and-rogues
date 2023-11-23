#include "Parameter.hpp"
#include <fstream>
#include <nlohmann/json_fwd.hpp>

#include <filesystem>
#include <iostream>

int main() {
  std::cout << "Current path" << std::filesystem::current_path() << std::endl;
  std::ifstream file("/home/vanish2/WorkSpace/CPP/dungoens-and-rogues/files/"
                     "init/parameters.json");
  if (file.is_open())
    std::cout << "!" << std::endl;
  nlohmann::json data = nlohmann::json::parse(file);
  file.close();

  std::ofstream save("/home/vanish2/WorkSpace/CPP/dungoens-and-rogues/files/"
                     "save/parameters.json");
  nlohmann::json save_obj;
  save_obj["primary"] = nlohmann::json::array();
  save_obj["secondary"] = nlohmann::json::array();

  for (auto &p : data["primary"]) {
    Parameter param;
    param.load(p);

    nlohmann::json saved_param = param.save();
    save_obj["primary"].push_back(saved_param);
  }
  save << save_obj;

  for (auto &p : data["secondary"]) {
    Parameter param;
    param.load(p);

    nlohmann::json saved_param = param.save();
    save_obj["secondary"].push_back(saved_param);
  }
  save << save_obj;
  save.close();

  return 0;
}
