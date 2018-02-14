#include "interpreter.h"
#include <iostream>

interpreter::interpreter(int block_size)
  : m_block_size(block_size)
{
}

void interpreter::attach_observer(std::shared_ptr<observer> obs)
{
  m_observers.push_back(obs);
}

void interpreter::notify_observers()
{
  for(auto obs : m_observers)
    obs->update();
}

void interpreter::run()
{
  std::string command;
  while(true)
  {
    std::getline(std::cin, command);
    if(command == "{")
      ;
    else if(command == "}")
      ;
    else
      ;
  }
}
