#include "disk.hpp"

Disk::Disk(std::string file_path) {
  vm = file_path;
}

void Disk::expand() {
  std::ofstream disk(vm, std::ios_base::app | std::ios_base::out);
  for (int i = 0; i < curr_size; i++) {
    disk << "\n";
  }

  curr_size *= 2;
}

void Disk::write(unsigned int address, unsigned int value) {
  if (address > curr_size) {
    expand();
  }
}

unsigned int Disk::read(unsigned int address) {
  // read from the file as the given address location
}

std::string Disk::fileLocation() const {
  return vm;
}

unsigned int Disk::getSize() const {
  return curr_size;
}