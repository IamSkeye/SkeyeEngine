#ifndef _WINDOW_H_
#define _WINDOW_H_

#pragma once

#include "Component.h"

#include <SDL2/SDL.h>
#include <GL/glew.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

namespace Skeye
{
  class Window : 
    public Component 
  {
  private:
    SDL_Window *window;
    int ef = 4;
   
  public:
    Window();
    ~Window();

    void onInit();
    void onDisplay();
  };
}

#endif
