#pragma once 

#include "observer.h"
#include "bulk.h"

class logger : public observer
{
  public:
    logger();
    void update() override;
    void set_bulk(std::shared_ptr<bulk> bulk_ptr) override;
};
