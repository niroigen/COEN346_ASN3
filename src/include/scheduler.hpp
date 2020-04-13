#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <vector>
#include "process.hpp"
#include "clock.hpp"

class Scheduler {
  private:
    Clock* clk;
    std::vector<Process> processes;
  public:
    void run();
};

#endif // SCHEDULER_HPP