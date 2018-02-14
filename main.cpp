#include "interpreter.h"
#include "bulk.h"
#include "logger.h"
#include "executor.h"

int main(int argc, char *argv[])
{
  if(argc == 2)
  {
    int block_size = std::stoi(argv[1]);

    std::shared_ptr<interpreter> interpreter_ptr = std::make_shared<interpreter>(block_size);
    std::shared_ptr<bulk> bulk_ptr = std::make_shared<bulk>();
    std::shared_ptr<logger> logger_ptr = std::make_shared<logger>();
    std::shared_ptr<executor> executor_ptr = std::make_shared<executor>();

    interpreter_ptr->attach_observer(bulk_ptr);
    bulk_ptr->attach_observer(logger_ptr);
    bulk_ptr->attach_observer(executor_ptr);

    interpreter_ptr->run();
  }

  return 0;
}
