#include <SkeyeEngine/Skeye.h>

#include <iostream>
#include <memory>

using namespace Skeye;

int main() 
{
  std::shared_ptr<Core> core = Core::initialize();

  std::shared_ptr<Entity> mainCamera = core->addEntity();
  std::shared_ptr<Camera> camera = mainCamera->addComponent<Camera>();
  std::shared_ptr<Transform> camTrans = mainCamera->addComponent<Transform>();

  std::shared_ptr<Entity> entity = core->addEntity();
  std::shared_ptr<Renderer> component = entity->addComponent<Renderer>();
  std::shared_ptr<Transform> trans = entity->addComponent<Transform>();

  core->run();

	return 0;
}