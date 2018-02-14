#pragma once

#include <observer/subject.h>
#include <observer/observer.h>
#include <vector>

class bulk
    : public subject
    , public observer
{
  public:
    void attach_observer(std::shared_ptr<observer> obs) override;
    void process_cmd();
    void notify_observers() override;
    void update(const std::string& cmd) override;

  private:
    std::vector<std::shared_ptr<observer>> m_observers;
    std::string m_commands_pipe;
};
