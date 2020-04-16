#include <iostream>
#include "shared/clock.hpp"
#include "shared/scheduler.hpp"
#include "shared/process.hpp"

int main() {
  // DEBUG( "Hello world" );
  Clock* clk = new Clock();
  Process* p1 = new Process(clk, 0, 1);
  Process* p2 = new Process(clk, 0, 4);

  std::vector<Process*> procs;
  procs.push_back(p1);
  procs.push_back(p2);
  Scheduler scheduler(clk, procs);
  
  clk->powerOn = true;
  std::thread tclk(&Clock::run, clk);
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::thread tsch(&Scheduler::run, scheduler);

  tsch.join();
  tclk.join();

  delete clk;
  clk = nullptr;
}