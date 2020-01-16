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

  class Component 
  {
  private:
    std::weak_ptr<Entity> entity;

  public:
    Component();
    ~Component();

    std::shared_ptr<Core> getCore();
    std::shared_ptr<Entity> getEntity();
    std::shared_ptr<Keyboard> getKeyboard();
    std::shared_ptr<Environment> getEnvironment();

    virtual void onInit() {};
    virtual void onStart() {};
    virtual void onTick() {};
    virtual void onDisplay() {};
    virtual void onPostDisplay() {};
    virtual void onGui() {};
    //TODO: Any other events you want to handle.
  };
}

#endif // !_COMPONENT_H_
