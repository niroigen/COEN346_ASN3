#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <string>
#include "clock.hpp"
#include "constants.hpp"

struct Process {
  Process(const Clock* _clk, unsigned int _start_time, unsigned int _burst_time, std::string _cmd) {
    clk = _clk;
    start_time = _start_time;
    burst_time = _burst_time;
    cmd = _cmd;
    state = READY;
  }
  const Clock* clk;
  unsigned int start_time;
  unsigned int burst_time;
  std::string cmd;
  std::string state;
};

#endif // PROCESS_HPP