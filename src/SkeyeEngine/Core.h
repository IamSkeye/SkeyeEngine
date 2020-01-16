#ifndef _CORE_H_
#define _CORE_H_

#pragma once

#include "NonCopyable.h"
#include "Entity.h"

#include <memory>
#include <list>

namespace Skeye
{
  class Environment;
  class Entity;
  class Keyboard;

  class Core : 
    private NonCopyable {
  private:
    std::weak_ptr<Core> self;
    std::shared_ptr<Environment> environment;
    std::shared_ptr<Keyboard> keyboard;
    std::list<std::shared_ptr<Entity>> entities;
    bool running;

  public:
    Core();
    ~Core();

    static std::shared_ptr<Core> initialize();
    std::shared_ptr<Entity> addEntity();

    void run();
    void stop();
  };
}
#endif