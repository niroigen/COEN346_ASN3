#include "gtest/gtest.h"
#include "vm_helper.hpp"

TEST(VMHelper, swappedVariable) {
  std::unordered_map<std::string, VMMData> mapping;
  VMMData data1, data2;
  data1.last_access = std::chrono::system_clock::now();
  data1.type = DISK;

  data2.last_access = std::chrono::system_clock::now();
  data2.type = MAIN_MEM;

  mapping["data1"] = data1;
  mapping["data2"] = data2;

  EXPECT_EQ(swappedVariable(mapping), "data2");
}