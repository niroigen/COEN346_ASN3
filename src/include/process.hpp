#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <string>
#include "clock.hpp"
#include "constants.hpp"

struct Process {
  Process(const Clock* _clk, unsigned int _start_time, unsigned int _burst_time, std::string cmd) {
    clk = _clk;
    start_time = _start_time;
  }
  const Clock* clk;
  unsigned int start_time;
  unsigned int burst_time;
  std::string cmd;
  std::string state = READY;
};

#endif // PROCESS_HPP