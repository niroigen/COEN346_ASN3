#include "gtest/gtest.h"
#include "main_memory.hpp"

TEST(MainMemory, init)
{
  MainMemory mem("memconfig.txt");
  EXPECT_EQ(mem.getSize(), 2);
}

TEST(MainMemory, writeAndWriteValid)
{
  MainMemory mem("memconfig.txt");
  mem.write(0,500);

  EXPECT_EQ(mem.read(0), 500);
}

TEST(MainMemory, writeInvalid)
{
  MainMemory mem("memconfig.txt");
  mem.write(5,500);

  EXPECT_EQ(mem.getSize(), 2);
}

TEST(MainMemory, readInvalid)
{
  MainMemory mem("memconfig.txt");
  mem.read(500);

  EXPECT_EQ(mem.getSize(), 2);
}