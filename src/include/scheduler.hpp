#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <vector>
#include "process.hpp"
#include "clock.hpp"
#include "scheduler_helper.hpp"
#include "constants.hpp"

class Scheduler {
  private:
    Clock* clk;
    std::vector<Process>* processes;
  public:
    Scheduler(Clock* clk, std::vector<Process>* processes);
    void run();
    void deployProcesses();
};

#endif // SCHEDULER_HPP