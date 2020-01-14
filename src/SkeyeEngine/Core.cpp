#include "Core.h"
#include "Entity.h"

namespace SkeyeEngine
{
  Core::Core() {}
  Core::~Core() {}

  std::shared_ptr<Core> Core::initialize()
  {
    std::shared_ptr<Core> rtn = std::make_shared<Core>();
    rtn->self = rtn;

    return rtn;
  }

  std::shared_ptr<Entity> Core::addEntity()
  {
    std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
    entities.push_back(rtn);
    rtn->core = self;

    return rtn;
  }

  void Core::run() {
    //running = true;
    while (running)
    {
		  for(std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
		  {
        (*it)->tick();
		  }

      for(std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
      {
        (*it)->display();
      }

      //TODO: Post display etc
    }
  }

  void Core::stop() 
  {

  }
}