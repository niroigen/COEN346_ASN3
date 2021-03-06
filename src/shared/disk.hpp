#ifndef DISK_HPP
#define DISK_HPP


#include <iostream>
#include <fstream>
#include <ios>
#include <string>
#include <limits>
#include <sstream>

class Disk {
  public:
    Disk(std::string file_path);
    void write(unsigned int address, unsigned int value);
    unsigned int read(unsigned int address);
    std::string fileLocation() const;
    void expand();
    unsigned int getSize() const;

  private:
    std::string vm;
    unsigned int curr_size;
};

#endif // DISK_HPP