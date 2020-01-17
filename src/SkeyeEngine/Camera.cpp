#include "Camera.h"
#include "Transform.h"
#include "Core.h"

#include <glm/glm.hpp>

namespace Skeye 
{
  Camera::Camera() {}
  Camera::~Camera() {}

  glm::mat4 Camera::getViewMatrix()
  {
    return glm::inverse(getTransform()->getModelMatrix());
  }

  glm::mat4 Camera::getProjMatrix()
  {
    return glm::perspective((glm::radians(45.0f)), float(WINDOW_WIDTH / WINDOW_HEIGHT), 0.1f, 100.0f);
  }

  void Camera::onInit() 
  {
    //getCore()->cameras.push_back(getEntity()->getComponent<Camera>());
    getCore()->currentCamera = getEntity()->getComponent<Camera>();
  }
}
