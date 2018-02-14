#pragma once

#include <memory>
#include <observer/observer.h>

class observer;

class subject
{
  public:
    virtual void attach_observer(std::shared_ptr<observer> obs) = 0;
    virtual void notify_observers() = 0;
};