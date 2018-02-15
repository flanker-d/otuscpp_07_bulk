#include <interpreter/interpreter.h>
#include <interpreter/simple_cmd_handler.h>
#include <iostream>

interpreter::interpreter(int block_size)
  : m_block_size(block_size)
  , m_cmd_handler(std::make_shared<simple_cmd_handler>())
{
}

void interpreter::process_cmd(const std::string& cmd)
{
  m_cmd_handler->process_cmd(cmd, shared_from_this());
}

void interpreter::change_state(const std::shared_ptr<cmd_handler>& state_handler)
{
  m_cmd_handler = state_handler;
}

const int&interpreter::block_size() const
{
  return m_block_size;
}

void interpreter::attach_observer(const std::shared_ptr<observer>& obs)
{
  m_observers.push_back(obs);
}

void interpreter::notify_observers(const std::string& commands_pipeline)
{
  for(auto obs : m_observers)
    obs->update(commands_pipeline);
}

void interpreter::run()
{

}
