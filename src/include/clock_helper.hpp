#ifndef CLOCK_HELPER_HPP
#define CLOCK_HELPER_HPP

#include <vector>
#include "process.hpp"

std::vector<Process*> processesStarting(std::vector<Process*> processes, unsigned int curr_time);

#endif // CLOCK_HELPER_HPP