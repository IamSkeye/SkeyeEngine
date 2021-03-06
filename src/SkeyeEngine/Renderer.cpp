#include "Core.h"
#include "Renderer.h"
#include "Transform.h"
#include "Camera.h"
#include "Exception.h"
#include "stb_image.h"

#include <fstream>
#include <iostream>

namespace Skeye
{
  Renderer::Renderer() {}
  Renderer::~Renderer() {}

  const GLchar *VertFragSrc =
    "\n#ifdef VERTEX\n                                                            \n" \
    "attribute vec3 in_Position;	                                                \n" \
    "attribute vec4 in_Color;			                                                \n" \
    "uniform mat4 in_Model;			                                                  \n" \
    "uniform mat4 in_View;			                                                  \n" \
    "uniform mat4 in_Proj;	                                                      \n" \
    "											                                                        \n" \
    "varying vec4 ex_Color;				                                                \n" \
    "											                                                        \n" \
    "void main()							                                                    \n" \
    "{                                                                            \n" \
    "	 gl_Position = in_Proj * in_View * in_Model * vec4(in_Position, 1.0);       \n" \
    "	 ex_Color = in_Color;			        	                                        \n" \
    "}							                  		                                        \n" \
    "\n#endif\n                                                                   \n" \
    "											                                                        \n" \
    "\n#ifdef FRAGMENT\n                                                          \n" \
    "varying vec4 ex_Color;		  	                                                \n" \
    "								                                                            	\n" \
    "void main()			      		                                                 	\n" \
    "{							            	                                                \n" \
    "  gl_FragColor = ex_Color;		                                                \n" \
    "}						            		                                                \n" \
    "\n#endif\n  					                                                        \n";
  
                                                                                        ///'in_Position' - For ensuring the shader is linked in the correct position to the VAO[?]
                                                                                       ///'in_Color'/'ex_Color' - For interpolating colors between vertex and fragment shaders
                                                                                      ///For any fragment drawn, use the colour stored in the uniform in_Color.
  const GLfloat	positions[] = {
    0.0f, 0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f
  };

  const GLfloat colors[] = {
    1.0f, 0.0f, 0.0f, 1.0f,
    0.0f, 1.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f, 1.0f
  };

  void Renderer::onInit() 
  {
    window = getCore()->getWindow();
    context = getCore()->getContext();

    ///
    ///VBO
    /// Mesh ////////
    GLuint positionsVboId = 0;

    ///Create a positions VBO on GPU
    glGenBuffers(1, &positionsVboId); ///(size, gives id to buffer using pointer [?])

    if (!positionsVboId)
    {
      throw std::exception();
    }

    ///Bind new VBO
    glBindBuffer(GL_ARRAY_BUFFER, positionsVboId); ///(target[?], The buffer Id to work with. cannot use pointers on gpu so we use the id.)

    ///Copy data from RAM to new VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW); ///(target[?], sets size to amount of items in 'positions' array, location of data to be copied, usage of data)
   
    ///Reset state
    glBindBuffer(GL_ARRAY_BUFFER, 0); ///(target[?], id set to 0 when unused so it does not accidnetly copy data where it is bound[?])

    GLuint colorsVboId = 0;

    ///Create a colors VBO on the GPU
    glGenBuffers(1, &colorsVboId);

    if (!colorsVboId)
    {
      throw std::exception();
    }

    ///Bind VBO
    glBindBuffer(GL_ARRAY_BUFFER, colorsVboId);

    ///Copy data from RAM to colors VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

    ///Reset state
    glBindBuffer(GL_ARRAY_BUFFER, 0); ///(target[?], id set to 0 when unused so it does not accidnetly copy data where it is bound[?])

    ///
    ///VAO

    vaoId = 0;

    ///Create new VAO on GPU
    glGenVertexArrays(1, &vaoId); ///(size, gives id to array using pointer [?])

    if (!vaoId)
    {
      throw std::exception();
    }

    ///Bind new VAO
    glBindVertexArray(vaoId); ///(target[?], The array Id to work with. cannot use pointers on gpu so we use the id.)

    ///Bind position of VBO, assign it to position 0 on bound VAO
    glBindBuffer(GL_ARRAY_BUFFER, positionsVboId);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *)0);

    ///Flag array to be used
    glEnableVertexAttribArray(0);

    ///Bind colors VBO
    glBindBuffer(GL_ARRAY_BUFFER, colorsVboId);

    ///Assign it to position 1 on the VAO
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *)0);

    ///Flag array to be used
    glEnableVertexAttribArray(1);

    ///ResetState
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

	loadModel("../res/curuthers/curuthers.mtl");
  ///loadTexture("../res/curuthers/curuthers.mtl");
  }

  void Renderer::onDisplay()
  {
    ///shader->setAttribute("", buffer);
    ///shader->render();

    std::cout << "Renderer::OnDisplay" << std::endl;
    bool quit = false;

    while (!quit)
    {
      SDL_Event event = { 0 };      ///Check for inputs

      while (SDL_PollEvent(&event)) ///if there was an input
      {
        if (event.type == SDL_QUIT) ///if the input was 'close button clicked'
        {
          quit = true;
        }
      }

      ///
      ///Drawing

      programId = 0;
      
      ///Bind the shader to change the uniform
      glUseProgram(programId);

      ///Reset State
      glUseProgram(0);

      ///Set clear color and clear screan
      glClearColor(1.0f, 0.0f, 0.0f, 1.0f); ///Clear refers to setting the color of untampered with pixels, as opposed to clearing the screen.
      glClear(GL_COLOR_BUFFER_BIT);

      ///Tell OpenGL to use the shader program and VAO
      glUseProgram(programId);
      glBindVertexArray(vaoId);

      context = getCore()->getContext();
      shader = context->createShader();
      shader->parse(VertFragSrc);
      shader->setUniform("in_Proj", perspective(radians(45.0f), 1.0f, 0.1f, 100.0f));
      shader->setUniform("in_Model", getTransform()->getModelMatrix());
      shader->setUniform("in_View", getCore()->getCamera()->getViewMatrix());

      shader->setMesh(mesh);

      ///Draw 3 vertices
      glDrawArrays(GL_TRIANGLES, 0, 3);

      ///Reset state
      glBindVertexArray(0);
      glUseProgram(0);

      ///swap openGL buffer with screen buffer
      SDL_GL_SwapWindow(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
  }

  void Renderer::loadModel(const char* path)
  {
    std::shared_ptr<Context> context = getCore()->getContext();

    shader = context->createShader();
    shader->parse(VertFragSrc);

    mesh = context->createMesh();
    {
      std::ifstream f;
      f.open(path);
      std::string obj;
      std::string line;

      while (!f.eof())
      {
        std::getline(f, line);
        obj += line + "\n";
      }

      mesh->parse(obj);
    }
  }

  void Renderer::loadTexture(const char* path)
  {
    std::sr1::shared_ptr<Texture> texture = context->createTexture();

    {
      int w = 0;
      int h = 0;
      int bpp = 0;

      unsigned char *data = stbi_load(path,
        &w, &h, &bpp, 3);

      if (!data)
      {
        throw Exception("Failed to open image");
      }

      texture->setSize(w, h);

      for (int y = 0; y < h; y++)
      {
        for (int x = 0; x < w; x++)
        {
          int r = y * w * 3 + x * 3;

          texture->setPixel(x, y, vec3(
            data[r] / 255.0f,
            data[r + 1] / 255.0f,
            data[r + 2] / 255.0f));
        }
      }

      stbi_image_free(data);
    }

    mesh->setTexture("u_Texture", texture);

  }
}