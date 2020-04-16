#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <atomic>
#include <thread>
#include <chrono>

struct Clock {
  std::atomic<unsigned int> time;
  bool powerOn = true;

  void run() {
    while(powerOn) {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      time++;
    }
  }
};

#endif // CLOCK_HPP