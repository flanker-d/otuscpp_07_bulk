#pragma once

#include <observer/subject.h>
#include <observer/observer.h>

class executor : public observer
{
  public:
    executor();
    void update() override;
};
