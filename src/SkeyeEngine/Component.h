#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#pragma once

#include <memory>

class Core;
class Entity;
class Keyboard;
class Environment;

class Component {
  private:
    std::weak_ptr<Entity> entity;

  public:
    std::shared_ptr<Core> getCore;
    std::shared_ptr<Entity> getEntity;
    std::shared_ptr<Keyboard> getKeyboard;
    std::shared_ptr<Environment> getEnvironment;

    void onInit();
    void onBegin();
    void onTick();
    void onDisplay();

};

#endif // !_COMPONENT_H_
