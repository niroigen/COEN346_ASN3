#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <fstream>
#include "clock.hpp"
#include "virtual_manager.hpp"
#include "constants.hpp"

struct Process {
  Process(const Clock* _clk, unsigned int _start_time, unsigned int _burst_time, unsigned int* _curr_line, VirtualManager* _vmm);
  bool operator==(const Process &rhs) const;
  void run();
  static void sleep(unsigned int time);
  static void logging(std::string log);
  unsigned int getCurrentLine(std::fstream& file);
  void performCmd();

  const Clock* clk;
  unsigned int* curr_line;
  unsigned int start_time;
  unsigned int burst_time;
  unsigned int remaining_time;
  unsigned int proc_id;
  static unsigned int id;
  VirtualManager* vmm;
  std::mutex mut;
  std::string cmd;
  std::string state;
};

#endif // PROCESS_HPP