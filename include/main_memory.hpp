#ifndef MAIN_MEMORY_H
#define MAIN_MEMORY_H

#include <map>

class MainMemory {
  public:
    MainMemory(std::string); // the path to memconfig.txt
  
  private:
    std::map<unsigned int, unsigned int> frames;
};

#endif // MAIN_MEMORY_H