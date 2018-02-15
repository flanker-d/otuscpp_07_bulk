#pragma once

#include <interpreter/interpreter.h>

class braces_handler
    : public cmd_handler
{
  public:
    void process_cmd(const std::string& cmd, std::shared_ptr<interpreter> ipr_ptr) override;
};
