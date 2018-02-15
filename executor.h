#pragma once

#include <observer/observer.h>

class executor
    : public commands_observer
{
  public:
    void update_commands_observer(const std::string& cmd) override;
};
