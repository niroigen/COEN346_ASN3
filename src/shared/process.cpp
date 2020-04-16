#include "process.hpp"
#define DEBUG(x) std::cout << "process.cpp: " + std::string(x) << std::endl;

unsigned int Process::id { 0 };

Process::Process(const Clock* _clk, unsigned int _start_time, unsigned int _burst_time, unsigned int* _curr_line,
                 VirtualManager* _vmm) {
  clk = _clk;
  start_time = _start_time;
  burst_time = _burst_time;
  remaining_time = _burst_time;
  state = READY;
  proc_id = id++;
  curr_line = _curr_line;
  vmm = _vmm;
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
      while(curr_time == clk->time) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); 
        mut.lock();
        
        std::fstream file("commands.txt");
        file.seekg(std::ios::beg);
        DEBUG(std::to_string(*curr_line -1));
        for(int i=0; i < *curr_line - 1; ++i){
          file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        std::string command;
        file >> command;

        if (command == STORE) {
          std::string var_id;
          unsigned int val;
          file >> var_id;
          file >> val;

          vmm->memStore(var_id, val);
          DEBUG(std::string("Process ") + std::to_string(proc_id) + std::string(", Store: Variable ") + var_id + std::string(", Value: ") + std::to_string(val));
        }
        else if (command == LOOKUP) {
          std::string var_id;
          file >> var_id;

          auto val = vmm->memLookup(var_id);
          DEBUG(std::string("Process ") + std::to_string(proc_id) + std::string(", Lookup: Variable ") + var_id + std::string(", Value: ") + std::to_string(val));
        }
        else if (command == RELEASE) {
          std::string var_id;
          file >> var_id;
          
          vmm->memFree(var_id);
          DEBUG(std::string("Process ") + std::to_string(proc_id) + std::string(", Release: Variable ") + var_id);
        }

        DEBUG(command);

        file.close();

        *curr_line = (*curr_line + 1) % 9;

        std::this_thread::sleep_for(std::chrono::milliseconds(600));

        mut.unlock();
      }

      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      remaining_time--;
    }
  }

  DEBUG("Finised");
}