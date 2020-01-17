#include "Core.h"
#include "Entity.h"
#include "Camera.h"


namespace Skeye
{
  Core::Core() {}
  Core::~Core() {}

  std::shared_ptr<Core> Core::initialize()
  {
    std::shared_ptr<Core> rtn = std::make_shared<Core>();
    rtn->self = rtn;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      throw std::exception();
    }

    rtn->window = SDL_CreateWindow("SkeyeEngine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

    if (!SDL_GL_CreateContext(rtn->window))
    {
      throw std::exception();
    }

    if (glewInit() != GLEW_OK)
    {
      throw std::exception();
    }

    rtn->currentCamera = std::make_shared<Camera>();
    rtn->context = Context::initialize();
    
    rtn->self = rtn;
    return rtn;


  }

  std::shared_ptr<Entity> Core::addEntity()
  {
    std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
    entities.push_back(rtn);
    rtn->core = self;

    rtn->self = rtn;

    return rtn;
  }

  void Core::run() 
  {
    while (running)
    {
		  for(std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
		  {
        (*it)->tick();
		  }

      for(std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
      {
        (*it)->display();
      }

      //TODO: Post display etc
    }
  }

  void Core::stop() 
  {

  }

  std::shared_ptr<Core> Core::getCore()
  {
    return self.lock();
  }

  std::shared_ptr<Context> Core::getContext()
  {
    return context;
  }
  
  std::shared_ptr<Camera> Core::getCamera()
  {
    return currentCamera;
  }

  SDL_Window* Core::getWindow()
  {
    return window;
  }
}