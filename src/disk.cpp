#include "disk.hpp"

Disk::Disk(std::string file_path) {
  vm = file_path;
}

void Disk::write(unsigned int address, unsigned int value) {
  // write to the file at the given address location
}

unsigned int Disk::read(unsigned int address) {
  // read from the file as the given address location
}