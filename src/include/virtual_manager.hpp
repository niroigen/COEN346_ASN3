#ifndef VIRTUAL_MANAGER_HPP
#define VIRTUAL_MANAGER_HPP

#include <unordered_map>
#include <string>
#include <chrono>
#include <set>
#include "vmm_data.hpp"
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
    bool isFull() const;
    unsigned int VirtualManager::getAvailableFrame(std::string mem_type) const;

  private:
    std::unordered_map<std::string, VMMData> mapping;
    std::set<unsigned int> main_mem_allocated_frames;
    std::set<unsigned int> disk_allocated_frames;
    Disk* disk = nullptr;
    MainMemory* main_mem = nullptr;
    unsigned int vars_in_main = 0;
};

#endif // VIRTUAL_MANAGER_HPP