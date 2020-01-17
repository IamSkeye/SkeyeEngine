#ifndef _MESH_RENDERER_H_
#define _MESH_RENDERER_H_

#pragma once

#include "Component.h"

#include <rend/rend.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define STB_IMAGE_IMPLEMENTATION

using namespace rend;

namespace Skeye
{
  class Renderer : 
    public Component 
  {
  private:
    std::shared_ptr<Context> context;
    std::shared_ptr<Shader> shader;
    std::shared_ptr<Mesh> mesh;
    
    GLuint vaoId;
    GLuint programId;
    SDL_Window *window;

  public:
    Renderer();
   ~Renderer();

   void onInit();
   void onDisplay();

   void loadModel(const char* path);
   void loadTexture(const char* path);
  };
}
#endif