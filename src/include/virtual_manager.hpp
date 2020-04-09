#ifndef VIRTUAL_MANAGER_HPP
#define VIRTUAL_MANAGER_HPP

#include <map>
#include "value_data.hpp"

class VirtualManager {
  public:
    VirtualManager();
    unsigned int memLoopup(std::string varId);
    void memStore(std::string varId, unsigned int value);
    void memFree(std::string varId);

  private:
    std::map<std::string, ValueData> map;
};

#endif // VIRTUAL_MANAGER_HPP