#ifndef MAIN_MEMORY_H
#define MAIN_MEMORY_H

#include <map>
#include <fstream>

class MainMemory {
  public:
    MainMemory(std::string); // the path to memconfig.txt
    void write(unsigned int address); // Address at this location
    unsigned int read(unsigned int address, unsigned int value);
    unsigned int getSize() const;
  
  private:
    std::map<unsigned int, unsigned int> frames;
};

#endif // MAIN_MEMORY_H