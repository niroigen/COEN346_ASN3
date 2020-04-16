#include "scheduler_helper.hpp"

void split(const std::string& str, std::vector<std::string>& cont)
{
    std::istringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         std::back_inserter(cont));
}

void retrieveProcesses(Clock* clk, std::vector<std::reference_wrapper<Process>> processes) {
  std::ifstream file("processes.txt");
  std::string str;
  std::string file_contents;
  int line = 0;
  unsigned int numprocs = 0;

  while (std::getline(file, str))
  {
    if (line == 0) {
      numprocs = std::stoi(str);
    }
    else {
      std::vector<std::string> data;
      split(str, data);
      Process p(clk, std::stoi(data[0]), std::stoi(data[1]));
      processes.push_back(p);
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