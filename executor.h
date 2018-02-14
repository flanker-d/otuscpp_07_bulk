#pragma once

#include <observer/subject.h>
#include <observer/observer.h>

class executor : public observer
{
  public:
    executor();
    void update(const std::string& cmd) override;
};
