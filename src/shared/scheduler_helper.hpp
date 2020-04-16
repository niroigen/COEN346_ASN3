#ifndef SCHEDULER_HELPER_HPP
#define SCHEDULER_HELPER_HPP

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>
#include "process.hpp"
#include "clock.hpp"

void split(const std::string& str, std::vector<Process*> cont);
void retrieveProcesses(Clock* clk, std::vector<Process*>& procs, VirtualManager* vmm, unsigned int*& curr_line);
bool areProcessesRunning(const std::vector<Process*> processes);

#endif // SCHEDULER_HELPER_HPP