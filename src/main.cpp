#include <iostream>
#include "shared/clock.hpp"
#include "shared/scheduler.hpp"
#include "shared/process.hpp"
#include "shared/virtual_manager.hpp"
#include "shared/disk.hpp"
#include "shared/main_memory.hpp"

int main() {
  Clock* clk = new Clock();
  
  Disk* diskptr = new Disk("vm.txt");
  MainMemory* main_memptr = new MainMemory("memconfig.txt");
  VirtualManager* vmm = new VirtualManager(*diskptr, *main_memptr);

  unsigned int* curr_line = new unsigned int(1);
  Process* p1 = new Process(clk, 2, 1, curr_line, vmm);
  Process* p2 = new Process(clk, 1, 2, curr_line, vmm);
  Process* p3 = new Process(clk, 2, 2, curr_line, vmm);

  std::vector<Process*> procs;
  procs.push_back(p1);
  procs.push_back(p2);
  procs.push_back(p3);
  Scheduler scheduler(clk, procs);
  
  clk->powerOn = true;
  std::thread tclk(&Clock::run, clk);
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::thread tsch(&Scheduler::run, scheduler);

  tsch.join();
  tclk.join();

  delete clk;
  clk = nullptr;

  delete curr_line;
  curr_line = nullptr;

  delete p1;
  p1 = nullptr;

  delete p2;
  p2 = nullptr;

  delete p3;
  p3 = nullptr;

  delete vmm;
  vmm = nullptr;
}