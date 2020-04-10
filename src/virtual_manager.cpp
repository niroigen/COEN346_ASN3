#include "virtual_manager.hpp"

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

}

void VirtualManager::memFree(std::string varId) {

}