#pragma once

#include "observer.h"
#include <vector>

class observer;

class bulk
{
  public:
    void subscribe(std::shared_ptr<observer> obs);
    void process_cmd();
    void notify();

  private:
    std::vector<std::shared_ptr<observer>> subs;
};
