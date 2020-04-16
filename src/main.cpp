#include <iostream>
#include "shared/clock.hpp"
#include "shared/scheduler.hpp"
#include "shared/process.hpp"
#include "shared/virtual_manager.hpp"
#include "shared/disk.hpp"
#include "shared/main_memory.hpp"
#include "shared/scheduler_helper.hpp"

int main() {
  Clock* clk = new Clock();
  
  Disk* diskptr = new Disk("vm.txt");
  MainMemory* main_memptr = new MainMemory("memconfig.txt");
  VirtualManager* vmm = new VirtualManager(*diskptr, *main_memptr);
  unsigned int* curr_line = nullptr;

  std::vector<Process*> procs;
  retrieveProcesses(clk, procs, vmm, curr_line);
  Scheduler scheduler(clk, procs);
  
  clk->powerOn = true;
  std::thread tclk(&Clock::run, clk);
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::thread tsch(&Scheduler::run, scheduler);

  tsch.join();
  tclk.join();

  for (auto process : procs) {
    delete process;
  }

  delete clk;
  clk = nullptr;

  delete curr_line;
  curr_line = nullptr;

  delete vmm;
  vmm = nullptr;
}