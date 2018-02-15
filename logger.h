#pragma once 

#include <observer/observer.h>

class logger : public observer
{
  public:
    logger();
    void update(const std::string& cmd) override;
};
