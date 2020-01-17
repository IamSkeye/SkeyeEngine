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
    localRotation = _rotation;
  }

  void Transform::setLocalScale(vec3 _scale)
  {
    localScale = _scale;
  }

  glm::mat4 Transform::getModelMatrix()
  {
    glm::mat4 mat(1.0f);

    mat = glm::translate(mat, localPosition);

    mat = glm::rotate(mat, localRotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    mat = glm::rotate(mat, localRotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    mat = glm::rotate(mat, localRotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

    mat = glm::scale(mat, localScale);

    return mat;
  }
}


