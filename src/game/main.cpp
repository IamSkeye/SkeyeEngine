#include <SkeyeEngine/SkeyeEngine.h>

#include <iostream>
#include <memory>

using namespace SkeyeEngine;

int main() 
{
  std::shared_ptr<Core> core = Core::initialize();
  std::shared_ptr<Entity> entity = core->addEntity();
  std::shared_ptr<MeshRenderer> component = entity->addComponent<MeshRenderer>();

  core->run();

	return 0;
}