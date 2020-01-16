#include <SkeyeEngine/Skeye.h>

#include <iostream>
#include <memory>

using namespace Skeye;

int main() 
{
  std::shared_ptr<Core> core = Core::initialize();
  std::shared_ptr<Entity> entity = core->addEntity();
  std::shared_ptr<Renderer> component = entity->addComponent<Renderer>();

  core->run();

	return 0;
}