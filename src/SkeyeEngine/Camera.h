#ifndef _CAMERA_H_
#define _CAMERA_H_

#pragma once

#include "Component.h"

#include <rend/rend.h>

using namespace rend;
/**
*Camera, holds data on where we are viewing the world from
*/

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
    glm::mat4 getProjMatrix();

    void onInit();
  };
}

#endif 
