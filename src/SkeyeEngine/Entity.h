#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <list>
#include <memory>

class Core;
class Component;

class Entity {
  private:
    std::weak_ptr<Core> core;
    std::list<std::shared_ptr<Component>> components;

  public:
    std::shared_ptr<Core> getCore();

    template<typename T, typename A>
    std::shared_ptr<T> addComponent(A a);

    template<typename T, typename A, typename B>
    std::shared_ptr<T> addComponent(A a, B b);

    template<typename T, typename A, typename B, typename C>
    std::shared_ptr<T> addComponent(A a, B b, C c);

    void tick();
    void display();

};

#endif // !_ENTITY_H_
