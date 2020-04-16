#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <atomic>
#include <thread>
#include <chrono>

#define DEBUG(x) std::cout << "clock.hpp: " + std::string(x) << std::endl;

struct Clock {
  std::atomic<unsigned int> time;
  bool powerOn = true;

  void run() {
    while(powerOn) {
      DEBUG( "Current time " + std::to_string(time) );
      std::this_thread::sleep_for(std::chrono::seconds(1));
      time++;
      DEBUG("");
    }
  }
};

#endif // CLOCK_HPP