#include "Core.h"
#include "Entity.h"
#include "Component.h"

namespace Skeye
{
  Entity::Entity() {}
  Entity::~Entity() {}

  std::shared_ptr<Core> Entity::getCore()
  {
    return core.lock();
  }

  void Entity::tick()
  {
    for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
    {
      (*it)->onTick();
    }
  }

  void Entity::display()
  {
    for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
    {
      (*it)->onDisplay();
    }
  }
}