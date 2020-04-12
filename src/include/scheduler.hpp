#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <vector>
#include "process.hpp"

struct Scheduler {
  unsigned int quantum_time;
  std::vector<Process*> processes;
  bool new_data;
  void run();
  void checkForNewProcess();
  bool isAlive;
  std::vector<Process*> new_processes;
  void placeProcess(Process& process);
};

#endif // SCHEDULER_HPP