#include "gtest/gtest.h"
#include "disk.hpp"

#include <fstream>
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

    static unsigned int readLine(unsigned int desired_line) {
      std::string line;
      std::ifstream vm("vm.txt");
      for(int i = 0; i < desired_line; ++i)
        std::getline(vm, line);

      std::getline(vm, line);
      std::stringstream stream(line);

      unsigned int id;
      stream>>id;

      return id;
    }

    static void write(unsigned int line, unsigned int value) {
      std::fstream file("vm.txt") ;
      if (!file)
        return;

      unsigned currentLine = 0 ;
      while (currentLine < line) {
        file.ignore( std::numeric_limits<std::streamsize>::max(), '\n');
        ++currentLine;
      }

      file.seekp(file.tellg());

      file << std::to_string(value);
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
  EXPECT_EQ(countLines("vm.txt"), disk->getSize());

  disk->expand();
  EXPECT_EQ(countLines("vm.txt"), disk->getSize());
}

TEST_F(DiskTest, write)
{
  disk->write(1,750);
  EXPECT_EQ(750, readLine(1));
}

TEST_F(DiskTest, read)
{
  write(1, 520);
  EXPECT_EQ(520, disk->read(1));
}