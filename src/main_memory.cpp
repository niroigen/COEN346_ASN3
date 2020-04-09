#include "main_memory.hpp"

MainMemory::MainMemory(std::string file_path) {
  std::ifstream file(file_path);
  std::string str;
  std::string file_contents;
  while (std::getline(file, str))
  {
    file_contents += str;
  }

  unsigned int num_frames = std::stoi(file_contents);
  
  for (unsigned int frame = 0; frame < num_frames; frame++) {
    frames[frame] = 0;
  }
}

unsigned int MainMemory::getSize() const {
  return frames.size();
}

void write(unsigned int address) { // Address at this location

}

unsigned int read(unsigned int address, unsigned int value) {

}