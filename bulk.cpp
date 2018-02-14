#include "bulk.h"
#include <iostream>

void bulk::attach_observer(std::shared_ptr<observer> obs)
{
  m_observers.push_back(obs);
}

void bulk::process_cmd()
{
  notify_observers();
}

void bulk::notify_observers()
{
  for (auto s : m_observers)
  {
    s->update(m_commands_pipe);
  }
}

void bulk::update(const std::string& cmd)
{
  std::cout << "bulk: " << cmd << std::endl;
  m_commands_pipe = std::move(cmd);
}
