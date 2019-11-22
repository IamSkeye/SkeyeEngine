#include "Component.h"

#include <SDL2/SDL.h>
#include <GL/glew.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

class MeshRenderer : Component {
  private:
    GLuint vaoId;
    GLuint programId;
    SDL_Window *window;


  public:
    void initialise();
    void renderer();
};