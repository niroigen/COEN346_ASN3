#ifndef VALUE_DATA_HPP
#define VALUE_DATA_HPP

#include <string>

struct ValueData {
  unsigned int last_access;
  unsigned int address;
  std::string type;
};

#endif // VALUE_DATA_HPP