#ifndef SCHEDULER_HELPER_HPP
#define SCHEDULER_HELPER_HPP

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include "process.hpp"
#include "clock.hpp"

void split(const std::string& str, std::vector<std::string>& cont);
std::vector<Process> retrieveProcesses(Clock* clk);
bool areProcessesRunning(const std::vector<Process>& processes);

#endif // SCHEDULER_HELPER_HPP