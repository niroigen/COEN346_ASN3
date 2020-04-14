#include "gtest/gtest.h"
#include "scheduler.hpp"

class SchedulerTest : public ::testing::Test {
  public:
    SchedulerTest() {}
  protected:
    void SetUp() override {
      clk = new Clock();
      
      procs->push_back(Process(clk, 2, 1));
      procs->push_back(Process(clk, 1, 2));
      procs->push_back(Process(clk, 2, 2));

      scheduler = new Scheduler(clk, procs);
    }

    void TearDown() override {
      delete clk;
      clk = nullptr;

      delete scheduler;
      scheduler = nullptr;
    }

    Clock* clk = nullptr;
    Scheduler* scheduler = nullptr;
    std::vector<Process>* procs = nullptr;
};

TEST_F(SchedulerTest, deployProcesses) {
  scheduler->deployProcesses();

  std::thread t(&Clock::run, clk);
  std::this_thread::sleep_for(std::chrono::seconds(5));

  clk->powerOn = false;
  t.join();

  EXPECT_EQ(areProcessesRunning(procs), false);
}