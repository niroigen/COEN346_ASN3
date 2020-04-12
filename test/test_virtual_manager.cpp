#include "gtest/gtest.h"
#include "virtual_manager.hpp"

class VirtualManagerTest : public ::testing::Test {
  public:
    VirtualManagerTest() {}
  protected:
    void SetUp() override {
      std::ofstream memconfig("memconfig.txt");
      memconfig << "2\n";
      memconfig.close();

      std::ofstream diskf("vm.txt", std::ios_base::app | std::ios_base::out);
      diskf << "\n";
      diskf.close();

      diskptr = new Disk("vm.txt");
      main_memptr = new MainMemory("memconfig.txt");

      vmm = new VirtualManager(*diskptr, *main_memptr);
    }

    void TearDown() override {
      remove("vm.txt");
      remove("memconfig.txt");

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