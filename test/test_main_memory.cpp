#include "gtest/gtest.h"
#include "main_memory.hpp"

class MainMemoryTest : public ::testing::Test {
  public:
    MainMemoryTest() {}
  protected:
    void SetUp() override {
      std::ofstream memconfig("memconfig.txt");
      memconfig << "2\n";
      memconfig.close();
      mem = new MainMemory("memconfig.txt");
    }

    void TearDown() override {
      remove("memconfig.txt");
      delete mem;
      mem = nullptr;
    }

    MainMemory* mem = nullptr;
};

TEST_F(MainMemoryTest, init) {
  EXPECT_EQ(mem->getSize(), 2);
}

TEST_F(MainMemoryTest, writeAndWriteValid) {
  mem->write(0,500);

  EXPECT_EQ(mem->read(0), 500);
}

TEST_F(MainMemoryTest, writeInvalid) {
  mem->write(5,500);

  EXPECT_EQ(mem->read(5), -1);
}

TEST_F(MainMemoryTest, readInvalid) {
  EXPECT_EQ(mem->read(5), -1);
}