#include <logger.h>
#include <iostream>

void logger::update_commands_observer(const std::string& cmd)
{
  m_output_file << cmd << std::endl;
  m_output_file.flush();
  m_output_file.close();
}

void logger::update_time_observer(const time_t& time)
{
  m_output_file = std::ofstream(get_new_filename(time));
}

std::string logger::get_new_filename(const time_t& time)
{
  return "bulk" + std::to_string(time) + ".log";
}
