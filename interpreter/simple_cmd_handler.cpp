#include <interpreter/simple_cmd_handler.h>
#include <interpreter/braces_handler.h>

void simple_cmd_handler::process_cmd(const std::string& cmd, std::shared_ptr<interpreter> ipr_ptr)
{
  if(cmd == "{")
  {
    m_commands_counter = 0;
    ipr_ptr->notify_observers(m_commands_pipeline);
    ipr_ptr->change_state(std::make_shared<braces_handler>());
  }
  else
  {
    if(m_commands_counter == 0)
      m_commands_pipeline = cmd;
    else
      m_commands_pipeline += ", " + cmd;

    m_commands_counter++;

    if(m_commands_counter == ipr_ptr->block_size())
    {
      ipr_ptr->notify_observers(m_commands_pipeline);
      m_commands_counter = 0;
    }
  }
}
