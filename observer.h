#pragma once

#include <memory>
#include "bulk.h"

class bulk;

class observer
    : public std::enable_shared_from_this<observer>
{
  public:
    virtual void update() = 0;
    virtual void set_bulk(std::shared_ptr<bulk> bulk_ptr) = 0;
};
