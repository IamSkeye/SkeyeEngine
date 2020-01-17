#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#pragma once

#include <memory>

namespace Skeye
{
  class Core;
  class Entity;
  class Keyboard;
  class Environment;
  class Transform;

  class Component 
  {
    friend class Entity;
  private:
    std::weak_ptr<Entity> entity;

  public:
    Component();
    ~Component();

    std::shared_ptr<Core> getCore();
    std::shared_ptr<Entity> getEntity();
    std::shared_ptr<Keyboard> getKeyboard();
    std::shared_ptr<Environment> getEnvironment();
    std::shared_ptr<Transform> getTransform();

    virtual void onInit() {};
    virtual void onStart() {};
    virtual void onTick() {};
    virtual void onDisplay() {};
    virtual void onPostDisplay() {};
    virtual void onGui() {};

  };
}

#endif // !_COMPONENT_H_