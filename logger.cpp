#include "logger.h"
#include <iostream>

logger::logger()
{
}

void logger::update(const std::string& cmd)
{
  std::cout << "logger:" << cmd << std::endl;
}
