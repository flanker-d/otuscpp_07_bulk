#include <executor.h>
#include <iostream>

void executor::update_commands_observer(const std::string& cmd)
{
  std::cout << "bulk: " << cmd << std::endl;
}
