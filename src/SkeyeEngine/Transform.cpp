#include "Transform.h"

namespace Skeye
{
  Transform::Transform() {}
  Transform::~Transform() {}

  void Transform::setLocalPosition(vec3 _position)
  {
    localPosition = _position;
  }

  void Transform::setLocalRotation(vec3 _rotation)
  {
    localPosition = _rotation;
  }

  void Transform::setLocalScale(vec3 _scale)
  {
    localPosition = _scale;
  }
}



