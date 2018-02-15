#pragma once

#include <interpreter/interpreter.h>
#include <logger.h>
#include <executor.h>

class bulk
{
  public:
    bulk(int block_size);

    void run();

  private:
    std::shared_ptr<interpreter> m_interpreter;
    std::shared_ptr<logger> m_logger;
    std::shared_ptr<executor> m_executor;
};
