#ifndef _SHADER_PROGRAM_H_
#define _SHADER_PROGRAM_H_

#pragma once

#include "Component.h"

#include <SDL2/SDL.h>
#include <GL/glew.h>

namespace Skeye
{
  class ShaderProgram
  {
  private:
    GLuint vaoId;
    GLuint programId;

  public:
    ShaderProgram();
    ~ShaderProgram();

    void setAttribute();
  };
}

#endif