#include "virtual_manager.hpp"

VirtualManager::VirtualManager(Disk& disk, MainMemory& main_mem) {
  diskptr = &disk;
  main_memptr = &main_mem;
}

VirtualManager::~VirtualManager() {
  delete diskptr;
  diskptr = nullptr;

  delete main_memptr;
  main_memptr = nullptr;
}

unsigned int VirtualManager::memLookup(std::string varId) {
  auto curr_time = std::chrono::system_clock::now();

  if (mapping.find(varId) != mapping.end()) {
    if (mapping[varId].type == MAIN_MEM) {
      mapping[varId].last_access = curr_time;

      return main_memptr->read(mapping[varId].address);
    }
    else if (mapping[varId].type == DISK) {
      std::string& disk_var = varId;
      std::string main_mem_var = swappedVariable(mapping);

      const unsigned int disk_val = diskptr->read(mapping[disk_var].address);
      const unsigned int main_mem_val = main_memptr->read(mapping[main_mem_var].address);

      diskptr->write(mapping[disk_var].address, main_mem_val);
      main_memptr->write(mapping[main_mem_var].address, disk_val);

      VMMData disk_data = mapping[disk_var];
      VMMData main_data = mapping[main_mem_var];

      mapping[disk_var] = main_data;
      mapping[main_mem_var] = disk_data;

      return disk_val;
    }
  }

  return -1;
}

void VirtualManager::memStore(std::string varId, unsigned int value) {
  auto curr_time = std::chrono::system_clock::now();

  if (mapping.find(varId) == mapping.end()) {
    std::string mem_type;

    if (!isFull()) {
      mem_type = MAIN_MEM;
    }
    else {
      mem_type = DISK;
    }

    unsigned int address = getAvailableFrame(mem_type);
    VMMData data;
    data.address = address;
    data.last_access = curr_time;
    data.type = mem_type;
    mapping[varId] = data;

    if (mem_type == MAIN_MEM) {
      main_mem_allocated_frames.insert(address);
    }
    else {
      disk_allocated_frames.insert(address);
    }
  }
}

void VirtualManager::memFree(std::string varId) {
  if (mapping.find(varId) != mapping.end()) {
    auto vmm_val = mapping[varId];
    if (vmm_val.type == MAIN_MEM) {
      main_mem_allocated_frames.erase(vmm_val.address);
    }
    else if (vmm_val.type == DISK) {
      disk_allocated_frames.erase(vmm_val.address);
    }
    mapping.erase(varId);
  }
}

bool VirtualManager::isFull() const {
  return vars_in_main == main_memptr->getSize();
}

unsigned int VirtualManager::getAvailableFrame(std::string mem_type) const {
  if (mem_type == MAIN_MEM) {
    for (auto frame : main_memptr->frames) {
      if (main_mem_allocated_frames.find(frame.first) == main_mem_allocated_frames.end()) {
        return frame.first;
      }
    }

    // Memory is full
    return -1;
  }
  else if (mem_type == DISK){
    for (auto frame = 0; frame < diskptr->getSize(); frame++) {
      if (disk_allocated_frames.find(frame) == disk_allocated_frames.end()) {
        return frame;
      }
    }

    // Memory is full, not possible because of disk being inifinite space
    return -1;
  }
}