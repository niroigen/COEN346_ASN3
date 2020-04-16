#include <iostream>
#include "shared/clock.hpp"
#include "shared/scheduler.hpp"
#include "shared/process.hpp"
#include "shared/virtual_manager.hpp"
#include "shared/disk.hpp"
#include "shared/main_memory.hpp"
#include "shared/scheduler_helper.hpp"

Clock* clk = new Clock();
Disk* diskptr;
MainMemory* main_memptr;
VirtualManager* vmm;
Scheduler* scheduler;
unsigned int* curr_line;
std::vector<Process*> procs;

void init();
void deinit();

int main() {
  init();

  std::thread tclk(&Clock::run, clk);
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::thread tsch(&Scheduler::run, scheduler);

  tsch.join();
  tclk.join();

  deinit();
}

void init() {
  clk = new Clock();
  diskptr = new Disk("vm.txt");
  main_memptr = new MainMemory("memconfig.txt");
  vmm = new VirtualManager(*diskptr, *main_memptr);

  retrieveProcesses(clk, procs, vmm, curr_line);
  scheduler = new Scheduler(clk, procs);
  clk->powerOn = true;
}

void deinit() {
  for (auto process : procs) {
    delete process;
  }

  delete clk;
  clk = nullptr;

  delete curr_line;
  curr_line = nullptr;

  delete vmm;
  vmm = nullptr;

  delete scheduler;
  scheduler = nullptr;
}