#include "disk.hpp"

Disk::Disk(std::string file_path) {
  vm = file_path;
  curr_size = 1;
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

  std::fstream file(vm) ;
  if (!file)
    return;

  unsigned currentLine = 0 ;
  while (currentLine < address) {
    file.ignore( std::numeric_limits<std::streamsize>::max(), '\n');
    ++currentLine;
  }

  file.seekp(file.tellg());

  file << std::to_string(value);
}

unsigned int Disk::read(unsigned int address) {
  std::string line;
  std::ifstream disk(vm);
  for(int i = 0; i < address; ++i)
    std::getline(disk, line);

  std::getline(disk, line);
  std::stringstream stream(line);

  unsigned int id;
  stream>>id;

  return id;
}

std::string Disk::fileLocation() const {
  return vm;
}

unsigned int Disk::getSize() const {
  return curr_size;
}