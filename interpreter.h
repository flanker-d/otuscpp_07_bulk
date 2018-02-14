#pragma once 

#include <observer/subject.h>
#include <vector>

class interpreter : public subject
{
  public:
    interpreter(int block_size);
    void attach_observer(std::shared_ptr<observer> obs) override;
    void notify_observers() override;
    void run();

  private:
    void process_cmd(const std::string& cmd);
    void try_to_notify_observers();

  private:
    std::vector<std::shared_ptr<observer>> m_observers;
    int m_block_size;
    int m_inner_blocks_counter = 0;
    int m_commands_counter = 0;
    std::string m_debug_str;
    std::string m_commands_pipe;
};
