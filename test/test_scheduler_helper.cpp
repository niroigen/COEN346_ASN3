#include "gtest/gtest.h"
#include "scheduler_helper.hpp"
#include "constants.hpp"

#include <fstream>
#include <cstdio>
class SchedulerHelperTest : public ::testing::Test {
  public:
    SchedulerHelperTest() {}
  protected:
    void SetUp() override {
      std::ofstream processes("processes.txt");
      processes << "3\n";
      processes << "2 1\n";
      processes << "1 2\n";
      processes << "2 2\n";

      clk = new Clock();

      procs = new std::vector<Process>();

      procs->push_back(Process(clk, 2, 1));
      procs->push_back(Process(clk, 1, 2));
      procs->push_back(Process(clk, 2, 2));
    }

    void TearDown() override {
      remove("processes.txt");
      delete clk;
      clk = nullptr;

      delete procs;
      procs = nullptr;
    }

    std::vector<Process>* procs = nullptr;
    Clock* clk = nullptr;
};

TEST_F(SchedulerHelperTest, split) {
  std::vector<std::string> actual;
  std::vector<std::string> expected {"hello", "my", "name", "is", "niroigen"};
  
  split("hello my name is niroigen", actual);
  EXPECT_EQ(actual, expected);
}

TEST_F(SchedulerHelperTest, retrieveProcesses) {
  std::vector<Process> actual_procs;
  retrieveProcesses(clk, actual_procs);

  std::vector<Process> expected_procs;
  expected_procs.push_back(Process(clk, 2, 1));
  expected_procs.push_back(Process(clk, 1, 2));
  expected_procs.push_back(Process(clk, 2, 2));

  EXPECT_EQ(actual_procs.size(), 3);
  EXPECT_EQ(actual_procs, expected_procs);
}

TEST_F(SchedulerHelperTest, allProcsRunning) {
  EXPECT_EQ(areProcessesRunning(procs), true);
}

TEST_F(SchedulerHelperTest, allProcsFinishedRunning) {
  procs->at(0).state = FINISHED;
  procs->at(1).state = FINISHED;
  procs->at(2).state = FINISHED;

  EXPECT_EQ(areProcessesRunning(procs), false);
}