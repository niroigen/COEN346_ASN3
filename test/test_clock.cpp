#include <thread>
#include <chrono>
#include "gtest/gtest.h"
#include "clock.hpp"

TEST(ClockTest, run) {
  Clock* clk = new Clock();
  std::thread t(&Clock::run, clk);
  std::this_thread::sleep_for(std::chrono::seconds(5));
  clk->powerOn = false;
  t.join();

  EXPECT_EQ(clk->time, 5);
}