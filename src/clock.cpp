#include "clock.hpp"

void Clock::run() {
  while(scheduler->isAlive) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    time++;

    auto procs_starting = processesStarting(processes, time);

    if (procs_starting.size() > 0) {
      scheduler->new_processes = procs_starting;
    }
  }
}