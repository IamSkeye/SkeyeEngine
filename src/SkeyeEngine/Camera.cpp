#include "Camera.h"
#include "Transform.h"

namespace Skeye {
  Camera::Camera() {}
  Camera::~Camera() {}

  glm::mat4 Camera::getViewMatrix()
  {
    return glm::inverse(getTransform()->getModelMatrix());
  }
}
