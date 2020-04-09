#include "gtest/gtest.h"
#include "main_memory.hpp"
#include <iostream>

TEST(MainMemory, init)
{
    std::cout << "starting" << std::endl;
    MainMemory mem("memconfig.txt");
    EXPECT_EQ(mem.getSize(), 2);
}