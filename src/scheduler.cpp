#include "scheduler.hpp"

Scheduler::Scheduler(Clock* clk, std::vector<Process>* processes) {
  this->processes = processes;
  this->clk = clk;
}

void Scheduler::run() {
  while(areProcessesRunning(processes)) {
    // check the time and see whether any process will be starting
    
  }

  clk->powerOn = false;
}

void Scheduler::deployProcesses() {
  int num_procs_started = 0;

  while(num_procs_started != processes->size()) {
    for (auto & proc : *processes) {
      if (proc.start_time == clk->time && proc.state == READY) {
        // Start the process
        proc.state = STARTED;
      }
    }
  }
}