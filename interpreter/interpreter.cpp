#include <interpreter/interpreter.h>
#include <interpreter/simple_cmd_handler.h>
#include <iostream>

interpreter::interpreter(int block_size)
  : m_block_size(block_size)
  , m_cmd_handler(std::make_unique<simple_cmd_handler>())
{
}

void interpreter::process_cmd(const std::string& cmd)
{
  m_cmd_handler->process_cmd(cmd, shared_from_this());
}

void interpreter::change_state(std::shared_ptr<cmd_handler> state_handler)
{
  m_cmd_handler.reset(state_handler.get());
}

const int&interpreter::block_size() const
{
  return m_block_size;
}

void interpreter::attach_observer(std::shared_ptr<observer> obs)
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
