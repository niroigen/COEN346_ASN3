#ifndef DISK_H
#define DISK_H

#include <string>

class Disk {
  public:
    Disk(std::string file_path);
    void write(unsigned int address, unsigned int value);
    unsigned int read(unsigned int address);

  private:
    std::string vm;
};

#endif // DISK_H