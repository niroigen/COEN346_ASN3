#include "gtest/gtest.h"
#include "scheduler_helper.hpp"

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
    }

    void TearDown() override {
      remove("processes.txt");
      delete clk;
      clk = nullptr;
    }

    Clock* clk = nullptr;
};

TEST_F(SchedulerHelperTest, split) {
  std::vector<std::string> actual;
  std::vector<std::string> expected {"hello", "my", "name", "is", "niroigen"};
  
  split("hello my name is niroigen", actual);
  EXPECT_EQ(actual, expected);
}

TEST_F(SchedulerHelperTest, retrieveProcesses) {
  auto actual_procs = retrieveProcesses(clk);

  std::vector<Process> expected_procs;
  expected_procs.push_back(Process(clk, 2, 1));
  expected_procs.push_back(Process(clk, 1, 2));
  expected_procs.push_back(Process(clk, 2, 2));

  EXPECT_EQ(actual_procs.size(), 3);
  EXPECT_EQ(actual_procs, expected_procs);
}