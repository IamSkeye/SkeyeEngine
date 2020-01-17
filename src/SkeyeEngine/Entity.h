#ifndef _ENTITY_H_
#define _ENTITY_H_

#pragma once

#include <memory>
#include <list>

namespace Skeye
{
  class Core;
  class Component;

  class Entity
  {
    friend class Core;
  private:
    std::weak_ptr<Core> core;
    std::weak_ptr<Entity> self;
    std::list<std::shared_ptr<Component>> components;

  public:
    Entity();
    ~Entity();

    std::shared_ptr<Core> getCore();
    
    template<typename T>
    std::shared_ptr<T> getComponent()
    {
      for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
      {
        std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(*it);
        if (rtn)
        {
          return rtn;
        }
      }
      throw std::exception();
    }

    template<typename T>
    std::shared_ptr<T> addComponent() 
    {
      std::shared_ptr<T> rtn = std::make_shared<T>();

      rtn->entity = self;

      components.push_back(rtn);
      rtn->onInit();

      return rtn;
    };

    template<typename T, typename A>
    std::shared_ptr<T> addComponent(A a)
    {
      std::shared_ptr<T> rtn = std::make_shared<T>();

      rtn->entity = self;

      components.push_back(rtn);
      rtn->onInit(A a);

      return rtn;
    };

    template<typename T, typename A, typename B>
    std::shared_ptr<T> addComponent(A a, B b)
    {
      std::shared_ptr<T> rtn = std::make_shared<T>();

      rtn->entity = self;

      components.push_back(rtn);
      rtn->onInit(A a, B b);

      return rtn;
    };

    template<typename T, typename A, typename B, typename C>
    std::shared_ptr<T> addComponent(A a, B b, C c)
    {
      std::shared_ptr<T> rtn = std::make_shared<T>();

      rtn->entity = self;

      components.push_back(rtn);
      rtn->onInit(A a, B b, C c);

      return rtn;
    };

    void tick();
    void display();

  };
}

#endif
