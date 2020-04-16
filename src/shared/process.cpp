#include "process.hpp"

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

void Process::sleep(unsigned int time) {
  std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

void Process::logging(std::string log) {
  std::cout << log << std::endl;
}

unsigned int Process::getCurrentLine(std::fstream& file) {
  file.seekg(std::ios::beg);
  for(int i=0; i < *curr_line - 1; ++i){
    file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  }
}

void Process::performCmd() {
  std::string command;
  std::fstream file("commands.txt");
  getCurrentLine(file);
  file >> command;

  if (command == STORE) {
    std::string var_id;
    unsigned int val;
    file >> var_id;
    file >> val;

    vmm->memStore(var_id, val);
    logging(std::string("Process ") + std::to_string(proc_id) + std::string(", Store: Variable ") + var_id + std::string(", Value: ") + std::to_string(val));
  }
  else if (command == LOOKUP) {
    std::string var_id;
    file >> var_id;

    auto val = vmm->memLookup(var_id);
    logging(std::string("Process ") + std::to_string(proc_id) + std::string(", Lookup: Variable ") + var_id + std::string(", Value: ") + std::to_string(val));
  }
  else if (command == RELEASE) {
    std::string var_id;
    file >> var_id;

    vmm->memFree(var_id);
    logging(std::string("Process ") + std::to_string(proc_id) + std::string(", Release: Variable ") + var_id);
  }

  file.close();
}

void Process::run() {
  std::string command;

  while(state != FINISHED) {
    while(state == READY || state == PAUSED) {
      sleep(400);
    }
    
    logging("Process started");
    
    while (state == STARTED || state == RESUMED) {
      if (remaining_time == 0) {
        state = FINISHED;
        break;
      }

      int curr_time = clk->time;
      while(curr_time == clk->time) {
        sleep(50);

        mut.lock();
        performCmd();
        *curr_line = (*curr_line + 1) % 9;
        sleep(600);
        mut.unlock();
      }

      sleep(50);
      remaining_time--;
    }
  }

  logging("Finised");
}