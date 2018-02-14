#include "executor.h"
#include <iostream>

executor::executor()
{
}

void executor::update(const std::string& cmd)
{
  std::cout << "executor:" << cmd << std::endl;
}


