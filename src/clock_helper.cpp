#include "clock_helper.hpp"

std::vector<Process*> processesStarting(std::vector<Process*> processes, unsigned int curr_time) {
  std::vector<Process*> procs_starting;

  for (auto process : processes) {
    if (curr_time == process->arrival_time) {
      procs_starting.push_back(process);
    }
  }

  return procs_starting;
}