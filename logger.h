#pragma once 

#include <observer/observer.h>
#include <bulk.h>

class logger : public observer
{
  public:
    logger();
    void update(const std::string& cmd) override;
};
