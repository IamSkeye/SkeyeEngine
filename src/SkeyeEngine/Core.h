#ifndef _CORE_H_
#define _CORE_H_

#pragma once

#include <memory>
#include <list>

class Environment;
class Entity;
class Keyboard;

class Core {
  private:
    std::shared_ptr<Environment> environment;
	  std::shared_ptr<Keyboard> keyboard;
    std::list<std::shared_ptr<Entity>> entities;
    bool running;

  public:
    static std::shared_ptr<Core> initialize();
	  std::shared_ptr<Entity> addEntitiy();

	  void start();
	  void stop();
};

#endif