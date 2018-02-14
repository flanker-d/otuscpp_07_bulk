#include "interpreter.h"
#include <iostream>

interpreter::interpreter(int block_size)
  : m_block_size(block_size)
{
}

void interpreter::attach_observer(std::shared_ptr<observer> obs)
{
  m_observers.push_back(obs);
}

void interpreter::notify_observers()
{
  for(auto obs : m_observers)
    obs->update(m_commands_pipe);
}

void interpreter::run()
{
  std::string command;
  while(true)
  {
    std::getline(std::cin, command);
    m_debug_str += command + " ";
    if(command == "{")
      m_inner_blocks_counter++;
    else if(command == "}")
    {
      m_inner_blocks_counter--;
      process_cmd(command);
    }
    else
    {
      process_cmd(command);
    }
  }
}

void interpreter::process_cmd(const std::string& cmd)
{
  if(m_inner_blocks_counter == 0)
  {
    m_commands_pipe += cmd + ", ";
    m_commands_counter++;
  }

}

void interpreter::try_to_notify_observers()
{
  if(m_commands_counter == 3)
    notify_observers();
}
