#ifndef VMM_DATA_HPP
#define VMM_DATA_HPP

#include <string>

struct VMMData {
  unsigned int last_access;
  unsigned int address;
  std::string type;
};

#endif // VMM_DATA_HPP