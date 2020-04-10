#ifndef MAIN_MEMORY_H
#define MAIN_MEMORY_H

#include <unordered_map>
#include <fstream>

class MainMemory {
  public:
    MainMemory(std::string); // the path to memconfig.txt
    void write(unsigned int address, unsigned int value); // Address at this location
    unsigned int read(unsigned int address);
    unsigned int getSize() const;
  
  private:
    std::unordered_map<unsigned int, unsigned int> frames;
    friend class VirtualManager;
};

#endif // MAIN_MEMORY_H