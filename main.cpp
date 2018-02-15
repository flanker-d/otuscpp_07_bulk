#include <interpreter/interpreter.h>
#include <bulk.h>
#include <logger.h>
#include <executor.h>

int main(int argc, char *argv[])
{
  if(argc == 2)
  {
    int block_size = std::stoi(argv[1]);

    std::shared_ptr<bulk> bulk_ptr = std::make_shared<bulk>(block_size);
    bulk_ptr->run();
  }

  return 0;
}
