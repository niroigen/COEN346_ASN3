#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <atomic>
#include <thread>

struct Clock {
  std::atomic<unsigned int> time;
  bool powerOn = true;

  void run() {
    while(powerOn) {
      std:
    }
  }
};

#endif // CLOCK_HPP