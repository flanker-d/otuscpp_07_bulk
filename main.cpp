#include <iostream>
#include "bulk.h"
#include "logger.h"
#include "executor.h"

int main(int, char *[])
{
  std::shared_ptr<bulk> bulk_ptr = std::make_shared<bulk>();

  std::shared_ptr<logger> logger_ptr = std::make_shared<logger>();
  logger_ptr->set_bulk(bulk_ptr);

  std::shared_ptr<executor> executor_ptr = std::make_shared<executor>();
  executor_ptr->set_bulk(bulk_ptr);

  bulk_ptr->process_cmd();

  return 0;
}
