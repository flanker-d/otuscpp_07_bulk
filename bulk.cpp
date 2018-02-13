#include "bulk.h"

void bulk::subscribe(std::shared_ptr<observer> obs)
{
  subs.push_back(obs);
}

void bulk::process_cmd()
{
  notify();
}

void bulk::notify()
{
  for (auto s : subs)
  {
    s->update();
  }
}
