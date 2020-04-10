#include "gtest/gtest.h"
#include "virtual_manager.hpp"

class VirtualManagerTest : public ::testing::Test {
  public:
    VirtualManagerTest() {}
  protected:
    void SetUp() override {
      vmm = new VirtualManager("vm.txt", "memconfig.txt");
    }

    void TearDown() override {
      delete vmm;
      vmm = nullptr;
    }

    VirtualManager* vmm = nullptr;
};

TEST_F(VirtualManagerTest, init) {
  EXPECT_FALSE(nullptr == vmm);
}

TEST_F(VirtualManagerTest, isFull) {
  EXPECT_FALSE(vmm->isFull());
}