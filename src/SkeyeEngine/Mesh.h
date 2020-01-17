#ifndef _MESH_H_
#define _MESH_H_

#pragma once

#include <rend/rend.h>

using namespace rend;

namespace Skeye
{
  class Mesh
  {
  private:


  public:
    Mesh();
    ~Mesh();

    void setPositions();
    void setColours();

    GLfloat getPositions();
    GLfloat getColours();
  };
}

#endif