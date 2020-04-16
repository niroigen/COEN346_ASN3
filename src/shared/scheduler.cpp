#include "scheduler.hpp"
#define DEBUG(x) std::cout << "scheduler.cpp: " + std::string(x) << std::endl;

Scheduler::Scheduler(Clock* clk, std::vector<Process*> processes) {
  this->processes = processes;
  this->clk = clk;
  curr_threads = 0;
}

void Scheduler::run() {
  std::vector<std::thread*> threads;
  for (auto proc : processes) {
    std::thread* t = new std::thread(&Process::run, proc);
    threads.push_back(t);
  }

  std::thread depl(&Scheduler::deployProcesses, this);

  while(areProcessesRunning(processes)) {
    Process* p1 = nullptr;
    Process* p2 = nullptr;

    if (!process_queue.empty()) {
      DEBUG( "There is a process " + std::to_string(process_queue.front()->proc_id));
      if (process_queue.front()->state != FINISHED) {
        p1 = process_queue.front();
        p1->state = RESUMED;
        process_queue.pop();
      }
      else {
        int proc_id = process_queue.front()->proc_id;
        process_queue.pop();
        DEBUG("GOODBYEEEE " + std::to_string(proc_id));
      }
    }

    // if (!process_queue.empty()) {
    //   if (process_queue.front().state != FINISHED) {
    //     p2 = &process_queue.front();
    //     if (p2->state == READY) p2->state = STARTED;
    //     else p2->state = RESUMED;
    //     process_queue.pop();
    //     process_queue.push(*p2);
    //   }
    //   else {
    //     process_queue.pop();
    //   }
    // }

    if (p1 != nullptr || p2 != nullptr) {
      std::this_thread::sleep_for(std::chrono::seconds(QUANTUM_TIME));

      if (p1->state != FINISHED) {
        p1->state = PAUSED;
        process_queue.push(p1);
      }
      else curr_threads--;
      
      // if (p2->state != FINISHED)
      //   p2->state = PAUSED;
    }
    else {
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  }

  for (int i = 0; i < threads.size(); i++) {
    threads[i]->join();
  }

  clk->powerOn = false;
  depl.join();
}

void Scheduler::deployProcesses() {
  int num_procs_started = 0;
  std::unordered_set<Process*> in_queue;

  while(num_procs_started != processes.size() && clk->powerOn) {
    for (auto proc : processes) {
      if (in_queue.find(proc) == in_queue.end() && proc->start_time == clk->time) {
        // Start the process
        num_procs_started++;
        process_queue.push(proc);
        in_queue.emplace(proc);

        if (curr_threads != NUM_CORES) {
          proc->state = STARTED;
          curr_threads++;
        }
      }
    }
  }

  DEBUG("DEPLOYED EVERYONE");
}