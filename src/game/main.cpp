#include <SkeyeEngine/SkeyeEngine.h>

using namespace SkeyeEngine;

int main() 
{
	//std::cout << "output\n";

  std::shared_ptr<Core> core = Core::initialize();
  std::shared_ptr<Entity> entity = core->addEntity();
  std::shared_ptr<Component> component = entity->addComponent<Component>();

  core->run();
 
  system("pause");

	return 0;
}