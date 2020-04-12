#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <vector>
#include <thread>
#include <chrono>
#include "process.hpp"
#include "scheduler.hpp"
#include "clock_helper.hpp"

struct Clock {
  Scheduler* scheduler;
  unsigned int time = 0;
  std::vector<Process*> processes;
  void run();
};

#endif // CLOCK_HPP