#ifndef VMM_DATA_HPP
#define VMM_DATA_HPP

#include <string>
#include <chrono>

struct VMMData {
  std::chrono::time_point<std::chrono::system_clock> last_access;
  unsigned int address;
  std::string type;
};

#endif // VMM_DATA_HPP