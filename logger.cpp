#include "logger.h"
#include <iostream>

logger::logger()
{
}

void logger::update()
{
  std::cout << "logger:" << std::endl;
}

void logger::set_bulk(std::shared_ptr<bulk> bulk_ptr)
{
  bulk_ptr->subscribe(shared_from_this());
}

