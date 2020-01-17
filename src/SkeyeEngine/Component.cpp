#include "Component.h"
#include "Entity.h"
#include "Transform.h"
#include "Keyboard.h"
#include "Environment.h"

namespace Skeye
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

  std::shared_ptr<Transform> Component::getTransform()
  {
     return getEntity()->getComponent<Transform>();
  }
}
// getTransform is a function inside Component class that does entity.lock()->getComponent<Transform>(); <- returns that
