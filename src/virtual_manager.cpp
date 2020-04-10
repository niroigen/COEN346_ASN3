#include "virtual_manager.hpp"

VirtualManager::VirtualManager(std::string disk_loc) {
  disk = new Disk(disk_loc);
}

VirtualManager::~VirtualManager() {
  delete disk;
  disk = nullptr;
}

unsigned int VirtualManager::memLoopup(std::string varId) {

}

void VirtualManager::memStore(std::string varId, unsigned int value) {

}

void VirtualManager::memFree(std::string varId) {

}