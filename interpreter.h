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
    std::vector<std::shared_ptr<observer>> m_observers;
    int m_block_size;
};
