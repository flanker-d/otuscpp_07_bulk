#pragma once

#include <interpreter/interpreter.h>

class simple_cmd_handler
    : public cmd_handler
{
  public:
    void process_cmd(const std::string& cmd, std::shared_ptr<interpreter> ipr_ptr) override;
  private:
    std::string m_commands_pipeline;
    int m_commands_counter = 0;
};
