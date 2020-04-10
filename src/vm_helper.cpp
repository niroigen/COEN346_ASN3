#include "vm_helper.hpp"
#include <iostream>

std::string swappedVariable(std::unordered_map<std::string, VMMData> mapping) {
  std::string swapped_var = "";
  auto earliest_time = std::chrono::system_clock::now();

  for (auto entry : mapping) {
    if (entry.second.last_access < earliest_time && entry.second.type == MAIN_MEM) {
      earliest_time = entry.second.last_access;
      swapped_var = entry.first;
    }
  }

  return swapped_var;
}