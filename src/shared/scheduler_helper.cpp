#include "scheduler_helper.hpp"

void split(const std::string& str, std::vector<std::string>& cont)
{
    std::istringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         std::back_inserter(cont));
}

void retrieveProcesses(Clock* clk, std::vector<Process*>& processes, VirtualManager* vmm, unsigned int*& curr_line) {
  std::ifstream file("processes.txt");
  std::string str;
  std::string file_contents;
  int line = 0;
  unsigned int numprocs = 0;
  curr_line = new unsigned int(1);

  while (std::getline(file, str))
  {
    if (line == 0) {
      numprocs = std::stoi(str);
    }
    else {
      std::vector<std::string> data;
      split(str, data);
      processes.push_back(new Process(clk, std::stoi(data[0]), std::stoi(data[1]), curr_line, vmm));
    }
    line++;
  }
}

bool areProcessesRunning(const std::vector<Process*> processes) {
  for (auto& process : processes) {
    if (process->state != FINISHED) {
      return true;
    }
  }

  return false;
}