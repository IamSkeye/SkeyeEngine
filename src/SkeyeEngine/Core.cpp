#include "Core.h"
#include "Entity.h"

namespace SkeyeEngine
{
  Core::Core() {}
  Core::~Core() {}

  std::shared_ptr<Core> Core::initialize()
  {
    std::shared_ptr<Core> rtn = std::make_shared<Core>();

    return rtn;
  }

  std::shared_ptr<Entity> Core::addEntity()
  {
    std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
    entities.push_back(rtn);

    return rtn;
  }

  void Core::run() {
    /*while (true)
    {

    }*/
  }

  void Core::stop() {

  }
}