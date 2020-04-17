#ifndef VIRTUAL_MANAGER_HPP
#define VIRTUAL_MANAGER_HPP

#include <unordered_map>
#include <string>
#include <chrono>
#include <set>
#include "clock.hpp"
#include "vmm_data.hpp"
#include "disk.hpp"
#include "main_memory.hpp"
#include "vm_helper.hpp"
#include "constants.hpp"

using namespace std;

class VirtualManager {
  public:
    VirtualManager(Disk& disk, MainMemory& main_mem, Clock* clk);
    ~VirtualManager();
    unsigned int memLookup(std::string varId);
    void memStore(std::string varId, unsigned int value);
    void memFree(std::string varId);
    bool isFull() const;
    unsigned int getAvailableFrame(std::string mem_type) const;
    void logging(std::string log) const;

  private:
    std::unordered_map<std::string, VMMData> mapping;
    std::set<unsigned int> main_mem_allocated_frames;
    std::set<unsigned int> disk_allocated_frames;
    Disk* diskptr;
    MainMemory* main_memptr;
    unsigned int vars_in_main;
    Clock* clk;
};

#endif // VIRTUAL_MANAGER_HPP