#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <string>
#include <thread>
#include <iostream>
#include "clock.hpp"
#include "constants.hpp"

struct Process {
  std::string state;
  unsigned int arrival_time;
  unsigned int burst_time;
  std::thread t;
  unsigned int time_left;
  unsigned int waiting_time;
  unsigned int age;
  Clock* clockptr = nullptr;

  const unsigned int QUANTUM_TIME = 3000;
  friend class Clock;

  void run();
};

#endif // PROCESS_HPP