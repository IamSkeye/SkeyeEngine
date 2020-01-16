#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#pragma once

#include "Component.h"

#include <rend/rend.h>

using namespace rend;

namespace Skeye
{
  class Transform :
    public Component
  {
  private:
    vec3 localPosition;
    vec3 localRotation;
    vec3 loaclScale;

  public:
    Transform();
    ~Transform();

    void translate(vec3 _amount);
    void rotate(vec3 _amount);
    void scale(vec3 _amount);

    void setLocalPosition(vec3 _position);
    void setLocalRotation(vec3 _rotation);
    void setLocalScale(vec3 _scale);

    void getModelMatrix();
  };
}

#endif 
