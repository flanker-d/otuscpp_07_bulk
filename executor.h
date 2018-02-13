#pragma once

#include "bulk.h"
#include "observer.h"

class executor : public observer
{
  public:
    executor();
    void set_bulk(std::shared_ptr<bulk> bulk_ptr) override;
    void update() override;
};
