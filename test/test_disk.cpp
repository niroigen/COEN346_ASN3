#include "gtest/gtest.h"
#include "disk.hpp"

#include <cstdio>
class DiskTest : public ::testing::Test {
  public:
    DiskTest() {}
  protected:
    void SetUp() override {
      std::ofstream diskf("vm.txt", std::ios_base::app | std::ios_base::out);
      diskf << "\n";
      disk = new Disk("vm.txt");
    }

    void TearDown() override {
      remove("vm.txt");
      delete disk;
      disk = nullptr;
    }

    static unsigned int countLines(std::string file_name) {
      std::ifstream myfile(file_name);

      myfile.unsetf(std::ios_base::skipws);

      return std::count(
          std::istream_iterator<char>(myfile),
          std::istream_iterator<char>(),
          '\n');
    }

    Disk* disk = nullptr;
};

TEST_F(DiskTest, init)
{
  EXPECT_EQ("vm.txt", disk->fileLocation());
}

TEST_F(DiskTest, expand)
{
    disk->expand();
    EXPECT_EQ(disk->getSize(), countLines("vm.txt"));

    disk->expand();
    EXPECT_EQ(disk->getSize(), countLines("vm.txt"));
}