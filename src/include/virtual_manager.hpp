#ifndef VIRTUAL_MANAGER_HPP
#define VIRTUAL_MANAGER_HPP

#include <map>
#include <string>
#include "value_data.hpp"
#include "disk.hpp"
#include "main_memory.hpp"

using namespace std;

class VirtualManager {
  public:
    VirtualManager(std::string disk_loc, std::string memconfig);
    ~VirtualManager();
    unsigned int memLoopup(std::string varId);
    void memStore(std::string varId, unsigned int value);
    void memFree(std::string varId);

  private:
    std::map<std::string, ValueData> mapping;
    Disk* disk = nullptr;
    MainMemory* main_mem = nullptr;
};

#endif // VIRTUAL_MANAGER_HPP