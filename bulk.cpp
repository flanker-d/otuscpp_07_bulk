#include <bulk.h>
#include <iostream>

bulk::bulk(int block_size)
  : m_interpreter(std::make_shared<interpreter>(block_size))
  , m_logger(std::make_shared<logger>())
  , m_executor(std::make_shared<executor>())
{
  m_interpreter->attach_commands_observer(m_logger);
  m_interpreter->attach_time_observer(m_logger);
  m_interpreter->attach_commands_observer(m_executor);
}

void bulk::run()
{
  std::string command;
  while(std::getline(std::cin, command))
  {
    m_interpreter->process_cmd(command);
  }
}
