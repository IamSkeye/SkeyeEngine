#ifndef _CORE_H_
#define _CORE_H_

#pragma once

#include "NonCopyable.h"
#include "Entity.h"

#include <SDL2/SDL.h>
#include <rend/rend.h>
#include <memory>
#include <list>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

using namespace rend;

/** Core
* This is the heart of our engine
* This will intialise the program, hold an array of all the entities in our world, and will handle our main game loop.
*/

namespace Skeye
{
  class Environment;
  class Entity;
  class Keyboard;
  class Camera;

  class Core : 
    private NonCopyable 
  {
    friend class Camera;
  private:
    std::weak_ptr<Core> self;
    //std::vector<std::weak_ptr<Camera>> cameras;

    std::shared_ptr<Environment> environment;
    std::shared_ptr<Keyboard> keyboard;
    std::shared_ptr<Context> context;
    std::shared_ptr<Camera> currentCamera;
    std::list<std::shared_ptr<Entity>> entities;
    
    SDL_Window *window;
    
    bool running;

  public:
    Core();
    ~Core();

    static std::shared_ptr<Core> initialize();
    std::shared_ptr<Core> getCore();
    std::shared_ptr<Entity> addEntity();
    std::shared_ptr<Context> getContext();
    std::shared_ptr<Camera> getCamera();
    SDL_Window* getWindow();

    void run();
    void stop();
  };
}
#endif