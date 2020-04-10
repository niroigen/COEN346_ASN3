#ifndef VIRTUAL_MANAGER_HPP
#define VIRTUAL_MANAGER_HPP

#include <map>
#include <string>
#include "value_data.hpp"
#include "disk.hpp"

using namespace std;

class VirtualManager {
  public:
    VirtualManager(std::string disk_loc);
    ~VirtualManager();
    unsigned int memLoopup(std::string varId);
    void memStore(std::string varId, unsigned int value);
    void memFree(std::string varId);

  private:
    std::map<std::string, ValueData> mapping;
    Disk* disk;
};

#endif // VIRTUAL_MANAGER_HPP