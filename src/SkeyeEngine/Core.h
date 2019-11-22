#ifndef _CORE_H_
#define _CORE_H_

#include <memory>
#include <list>

class Environment;
class Entity;
class Keyboard;

class Core {
  private:
    std::shared_ptr<Environment> environment;
	  std::list<std::shared_ptr<Entity>> entities;
	  std::shared_ptr<Keyboard> keyboard;
	  bool running;

  public:
    static std::shared_ptr<Core> initialize();
	  std::shared_ptr<Entity> addEntitiy();

	  void start();
	  void stop();

};

#endif