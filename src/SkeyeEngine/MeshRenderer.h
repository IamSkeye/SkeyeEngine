#ifndef _MESH_RENDERER_H_
#define _MESH_RENDERER_H_

#pragma once

#include "Component.h"

#include <SDL2/SDL.h>
#include <GL/glew.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

namespace SkeyeEngine
{
  class MeshRenderer : public Component {
  private:
    GLuint vaoId;
    GLuint programId;
    SDL_Window *window;


  public:
    MeshRenderer();
   ~MeshRenderer();

   void onInit();
   void onDisplay();
  };
}
#endif