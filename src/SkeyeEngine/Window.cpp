#include "Window.h"
#include "Exception.h"
#include <iostream>

namespace Skeye
{
  Window::Window() {}
  Window::~Window() {}

  void Window::onInit()
  {
    //Window setup

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      throw std::exception();
    }
    
    window = SDL_CreateWindow("Triangle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

    if (!SDL_GL_CreateContext(window))
    {
      throw std::exception();
    }

    if (glewInit() != GLEW_OK)
    {
      throw std::exception();
    }
  }

  void Window::onDisplay()
  {
    std::cout << "Window::OnDisplay" << std::endl;
    bool quit = false;

    while (!quit)
    {
      SDL_Event event = { 0 };      //Check for inputs

      while (SDL_PollEvent(&event)) //if there was an input
      {
        if (event.type == SDL_QUIT) //if the input was 'close button clicked'
        {
          quit = true;
        }
      }

      //swap openGL buffer with screen buffer
      SDL_GL_SwapWindow(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
  }
}
