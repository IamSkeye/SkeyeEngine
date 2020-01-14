#include "Entity.h"

namespace SkeyeEngine
{
  Entity::Entity() {}
  Entity::~Entity() {}

  std::shared_ptr<Core> getCore()
  {
    return 0;
  }

  //template<typename T>
  //std::shared_ptr<T> Entity::addComponent()
  //{
  //  std::shared_ptr<T> rtn = std::make_shared<T>();

  //  components.push_back(rtn);
  //  rtn->OnInitialized();

  //  return rtn;
  //}


  void tick()
  {

  }

  void display()
  {

  }
}