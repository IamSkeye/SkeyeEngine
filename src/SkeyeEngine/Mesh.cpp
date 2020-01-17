#include "Mesh.h"

namespace Skeye
{
  Mesh::Mesh() {}
  Mesh::~Mesh() {}

  const GLfloat positions[] = {
  0.0f, 0.5f, 0.0f,
  -0.5f, -0.5f, 0.0f,
  0.5f, -0.5f, 0.0f
  };

  const GLfloat colors[] = {
  1.0f, 0.0f, 0.0f, 1.0f,
  0.0f, 1.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 1.0f, 1.0f
  };

  GLfloat Mesh::getPositions()
  {
    return 0;
  }
}