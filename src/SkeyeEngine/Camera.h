#ifndef _CAMERA_H_
#define _CAMERA_H_

#pragma once

#include "Component.h"

#include <rend/rend.h>

using namespace rend;

namespace Skeye
{
  class Camera :
    public Component
  {
  private:
       

  public:
    Camera();
    ~Camera();

    glm::mat4 getViewMatrix();
  };
}

#endif 
