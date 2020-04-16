#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <iostream>
#include <string>
#include <thread>
#include "clock.hpp"
#include "constants.hpp"

struct Process {
  Process(const Clock* _clk, unsigned int _start_time, unsigned int _burst_time);
  bool operator==(const Process &rhs) const;
  void run();

  const Clock* clk;
  unsigned int start_time;
  unsigned int burst_time;
  unsigned int remaining_time;
  unsigned int proc_id;
  static unsigned int id;
  std::string cmd;
  std::string state;
};

#endif // PROCESS_HPP