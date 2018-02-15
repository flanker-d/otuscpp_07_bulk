#pragma once 

#include <observer/observer.h>
#include <fstream>

class logger
    : public commands_observer
    , public time_observer
{
  public:
    void update_commands_observer(const std::string& cmd) override;
    void update_time_observer(const std::time_t& time) override;

  private:
    std::string get_new_filename(const time_t& time);

  private:
    std::ofstream m_output_file;
};
