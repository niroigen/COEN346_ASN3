#include "gtest/gtest.h"
#include "virtual_manager.hpp"

class VirtualManagerTest : public ::testing::Test {
  public:
    VirtualManagerTest() {}
  protected:
    void SetUp() override {
      diskptr = new Disk("vm.txt");
      main_memptr = new MainMemory("memconfig.txt");
      vmm = new VirtualManager(*diskptr, *main_memptr);
    }

    void TearDown() override {
      delete diskptr;
      diskptr = nullptr;

      delete main_memptr;
      main_memptr = nullptr;

      delete vmm;
      vmm = nullptr;
    }

    VirtualManager* vmm = nullptr;
    Disk* diskptr = nullptr;
    MainMemory* main_memptr = nullptr;
};

TEST_F(VirtualManagerTest, init) {
  EXPECT_FALSE(nullptr == vmm);
}

TEST_F(VirtualManagerTest, isFull) {
  EXPECT_FALSE(vmm->isFull());
}

TEST_F(VirtualManagerTest, getAvailableFrame) {
  EXPECT_TRUE((unsigned int)-1 != vmm->getAvailableFrame("MAIN"));
}