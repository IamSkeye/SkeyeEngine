#ifndef _ENTITY_H_
#define _ENTITY_H_

#pragma once

#include <memory>
#include <list>

namespace SkeyeEngine
{
  class Core;
  class Component;

class Entity {
private:
  std::weak_ptr<Core> core;
  std::list<std::shared_ptr<Component>> components;

public:
  Entity();
  ~Entity();

  std::shared_ptr<Core> getCore();

  template<typename T>
  std::shared_ptr<T> addComponent() 
  {
    std::shared_ptr<T> rtn = std::make_shared<T>();

    components.push_back(rtn);
    //rtn->OnInitialized();

    return rtn;
  }

  template<typename T, typename A>
  std::shared_ptr<T> addComponent(A a);

  template<typename T, typename A, typename B>
  std::shared_ptr<T> addComponent(A a, B b);

  template<typename T, typename A, typename B, typename C>
  std::shared_ptr<T> addComponent(A a, B b, C c);

  void tick();
  void display();

};
}

#endif
