#ifndef MAIN_MEMORY_H
#define MAIN_MEMORY_H

#include <map>

class MainMemory {
  public:
    MainMemory(std::string); // the path to memconfig.txt
    void write(unsigned int address); // Address at this location
    unsigned int read(unsigned int address, unsigned int value);
  
  private:
    std::map<unsigned int, unsigned int> frames;
};

#endif // MAIN_MEMORY_H