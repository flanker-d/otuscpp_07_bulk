#include "executor.h"
#include <iostream>

executor::executor()
{
}

void executor::update()
{
  std::cout << "executor:" << std::endl;
}

void executor::set_bulk(std::shared_ptr<bulk> bulk_ptr)
{
  bulk_ptr->subscribe(shared_from_this());
}

