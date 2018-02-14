#pragma once

#include <memory>
#include <observer/subject.h>

class subject;

class observer
    : public std::enable_shared_from_this<observer>
{
  public:
    virtual void update(const std::string& cmd) = 0;
};
