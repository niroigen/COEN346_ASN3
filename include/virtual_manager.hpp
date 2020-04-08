#ifndef VIRTUAL_MANAGER_HPP
#define VIRTUAL_MANAGER_HPP

#include <map>
#include "value_data.hpp"

class VirtualManager {
  public:
    VirtualManager();

  private:
    std::map<std::string, ValueData> map;
};

#endif // VIRTUAL_MANAGER_HPP