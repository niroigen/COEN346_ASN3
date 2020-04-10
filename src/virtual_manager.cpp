#include "virtual_manager.hpp"

const std::string VirtualManager::MAIN_MEM = "MAIN";
const std::string VirtualManager::DISK = "DISK";

VirtualManager::VirtualManager(std::string disk_loc, std::string memconfig) {
  disk = new Disk(disk_loc);
  main_mem = new MainMemory(memconfig);
}

VirtualManager::~VirtualManager() {
  delete disk;
  disk = nullptr;

  delete main_mem;
  main_mem = nullptr;
}

unsigned int VirtualManager::memLoopup(std::string varId) {

}

void VirtualManager::memStore(std::string varId, unsigned int value) {
  auto curr_time = std::chrono::system_clock::now();

  if (mapping.find(varId) != mapping.end()) {
    if (!isFull()) {
      unsigned int address = getAvailableFrame(MAIN_MEM);

      if (address != -1) {
        mapping[varId] = VMMData{curr_time, address, MAIN_MEM};
      }
    }
  }
}

void VirtualManager::memFree(std::string varId) {

}

bool VirtualManager::isFull() const {
  return vars_in_main == main_mem->getSize();
}

unsigned int VirtualManager::getAvailableFrame(std::string mem_type) const {
  if (mem_type == MAIN_MEM) {
    for (auto frame : main_mem->frames) {
      if (main_mem_allocated_frames.find(frame.first) != main_mem_allocated_frames.end()) {
        return frame.first;
      }
    }

    // Memory is full
    return -1;
  }
}