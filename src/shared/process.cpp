#include "process.hpp"
#define DEBUG(x) std::cout << "process.cpp: " + std::string(x) << std::endl;

unsigned int Process::id { 0 };

Process::Process(const Clock* _clk, unsigned int _start_time, unsigned int _burst_time) {
  clk = _clk;
  start_time = _start_time;
  burst_time = _burst_time;
  remaining_time = _burst_time;
  state = READY;
  proc_id = id++;
}

bool Process::operator==(const Process &rhs) const {
  return rhs.clk == clk && rhs.start_time == start_time && rhs.burst_time == burst_time && rhs.state == state;
}

void Process::run() {
  while(state != FINISHED) {
    while(state == READY || state == PAUSED) {
      std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
    
    DEBUG( "Process started" );
    
    while (state == STARTED || state == RESUMED) {
      DEBUG(std::to_string(remaining_time));
      if (remaining_time == 0) {
        state = FINISHED;
        break;
      }

      int curr_time = clk->time;

      while(curr_time == clk->time);
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      remaining_time--;
    }
  }

  DEBUG("Finised");
}