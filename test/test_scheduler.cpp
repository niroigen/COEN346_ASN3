#include "gtest/gtest.h"
#include "scheduler.hpp"

class SchedulerTest : public ::testing::Test {
  public:
    SchedulerTest() {}
  protected:
    static bool didAllProcessStart(std::vector<Process>* procs) {
      for (auto it = procs->begin(); it < procs->end(); it++) {
        if (it->state == READY) return false;
      }

      return true;
    }
    void SetUp() override {
      clk = new Clock();

      procs = new std::vector<Process>();
      
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

      delete procs;
      scheduler = nullptr;
    }

    Clock* clk = nullptr;
    Scheduler* scheduler = nullptr;
    std::vector<Process>* procs = nullptr;
};

TEST_F(SchedulerTest, deployProcessesToIncompletion) {

  std::thread t(&Clock::run, clk);
  std::thread depl(&Scheduler::deployProcesses, scheduler);

  std::this_thread::sleep_for(std::chrono::seconds(1));

  clk->powerOn = false;
  t.join();
  depl.join();

  EXPECT_EQ(SchedulerTest::didAllProcessStart(procs), false);
}

TEST_F(SchedulerTest, deployProcessesToCompletion) {
  std::thread t(&Clock::run, clk);
  std::thread depl(&Scheduler::deployProcesses, scheduler);

  std::this_thread::sleep_for(std::chrono::seconds(5));

  clk->powerOn = false;
  t.join();
  depl.join();

  EXPECT_EQ(SchedulerTest::didAllProcessStart(procs), true);
}