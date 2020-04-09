#include "gtest/gtest.h"
#include "disk.hpp"

TEST(Disk, init)
{
    Disk disk("vm.txt");
    EXPECT_EQ(disk.fileLocation(), "vm.txt");
}