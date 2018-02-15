#pragma once 

#include <observer/subject.h>
#include <interpreter/cmd_handler.h>
#include <vector>

class interpreter
    : public subject
    , public std::enable_shared_from_this<interpreter>
{
  public:
    interpreter(int block_size);
    void process_cmd(const std::string& cmd);

    void change_state(std::shared_ptr<cmd_handler> state_handler);
    const int& block_size() const;

    void attach_observer(std::shared_ptr<observer> obs) override;
    void notify_observers(const std::string& commands_pipeline) override;
    void run();

  private:
    void append_cmd(const std::string& cmd);

  private:
    std::vector<std::shared_ptr<observer>> m_observers;
    int m_block_size;
    std::unique_ptr<cmd_handler> m_cmd_handler;
};
