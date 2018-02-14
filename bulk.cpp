#include "bulk.h"

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
    s->update();
  }
}

void bulk::update()
{
}
