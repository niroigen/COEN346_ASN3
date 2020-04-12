#include "process.hpp"

void Process::run() {
  auto current_time = clockptr->time;

  while(state != READY);
  auto init_wait_time = clockptr->time;
  auto waiting_time = init_wait_time - current_time;
  std::cout << STARTED << std::endl;
  while(time_left != 0) {
    current_time = clockptr->time;
    while(state != RUNNING);
    waiting_time = current_time - arrival_time;
    age = 0;
    std::cout << RESUMED << std::endl;
    while(state != RUNNING);
    time_left -= QUANTUM_TIME;
    std::cout << PAUSED << std::endl;
  }
  std::cout << FINISHED << std::endl;
}