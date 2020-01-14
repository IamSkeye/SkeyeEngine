#include "Component.h"
#include "Entity.h"

namespace SkeyeEngine
{
  Component::Component() {}
  Component::~Component() {}

  std::shared_ptr<Core> Component::getCore()
  {
    return getEntity()->getCore();
  }

  std::shared_ptr<Entity> Component::getEntity()
  {
    return entity.lock();
  }

  std::shared_ptr<Keyboard> Component::getKeyboard()
  {
    return 0;
  }

  std::shared_ptr<Environment> Component::getEnvironment()
  {
    return 0;
  }
}