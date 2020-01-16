#include "Renderer.h"
#include "Exception.h"
#include <iostream>

namespace Skeye
{
  Renderer::Renderer() 
  {
    context = Context::initialize();
    shader = context->createShader();
    //shader->setSource();

    buffer = context->createBuffer();
    //buffer->add(vec3(1, 0, 0));
  }
  Renderer::~Renderer() {}

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

  //Vertex shader source code
  const GLchar *vertexShaderSrc =
    "attribute vec3 in_Position;	           " \
    "attribute vec4 in_Color;			           " \
    "											                   " \
    "varying vec4 ex_Color;				           " \
    "											                   " \
    "void main()							               " \
    "{                                       " \
    "	 gl_Position = vec4(in_Position, 1.0); " \
    "	 ex_Color = in_Color;			        	   " \
    "}							                  		   ";  //'in_Position' - For ensuring the shader is linked in the correct position to the VAO[?]
                                                //'in_Color'/'ex_Color' - For interpolating colors between vertex and fragment shaders

  //Fragment shader source code
  const GLchar *fragmentShaderSrc =
    "varying vec4 ex_Color;		  	" \
    "								            	" \
    "void main()			      			" \
    "{							            	" \
    "  gl_FragColor = ex_Color;		" \
    "}						            		";  //For any fragment drawn, use the colour stored in the uniform in_Color.

  void Renderer::onInit() 
  {
    //Window setup

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      throw std::exception();
    }

    window = SDL_CreateWindow("Triangle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

    if (!SDL_GL_CreateContext(window))
    {
	    throw std::exception();
    }

    if (glewInit() != GLEW_OK)
    {
	    throw std::exception();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
    //VBO

    GLuint positionsVboId = 0;

    //Create a positions VBO on GPU
    glGenBuffers(1, &positionsVboId); //(size, gives id to buffer using pointer [?])

    if (!positionsVboId)
    {
      throw std::exception();
    }

    //Bind new VBO
    glBindBuffer(GL_ARRAY_BUFFER, positionsVboId); //(target[?], The buffer Id to work with. cannot use pointers on gpu so we use the id.)

    //Copy data from RAM to new VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW); //(target[?], sets size to amount of items in 'positions' array, location of data to be copied, usage of data)

    //Reset state
    glBindBuffer(GL_ARRAY_BUFFER, 0); //(target[?], id set to 0 when unused so it does not accidnetly copy data where it is bound[?])

    GLuint colorsVboId = 0;

    //Create a colors VBO on the GPU
    glGenBuffers(1, &colorsVboId);

    if (!colorsVboId)
    {
      throw std::exception();
    }

    //Bind VBO
    glBindBuffer(GL_ARRAY_BUFFER, colorsVboId);

    //Copy data from RAM to colors VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

    //Reset state
    glBindBuffer(GL_ARRAY_BUFFER, 0); //(target[?], id set to 0 when unused so it does not accidnetly copy data where it is bound[?])

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //VAO

    vaoId = 0;

    //Create new VAO on GPU
    glGenVertexArrays(1, &vaoId); //(size, gives id to array using pointer [?])

    if (!vaoId)
    {
      throw std::exception();
    }

    //Bind new VAO
    glBindVertexArray(vaoId); //(target[?], The array Id to work with. cannot use pointers on gpu so we use the id.)

    //Bind position of VBO, assign it to position 0 on bound VAO
    glBindBuffer(GL_ARRAY_BUFFER, positionsVboId);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *)0);

    //Flag array to be used
    glEnableVertexAttribArray(0);

    //Bind colors VBO
    glBindBuffer(GL_ARRAY_BUFFER, colorsVboId);

    //Assign it to position 1 on the VAO
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *)0);

    //Flag array to be used
    glEnableVertexAttribArray(1);

    //ResetState
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    //Create new vertex shader
    GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);

    //Attach source code
    glShaderSource(vertexShaderId, 1, &vertexShaderSrc, NULL); //(Shader, Count, Source code location, length[?])

    //Compile shader
    glCompileShader(vertexShaderId);

    //Check for errors
    GLint success = 0;
    glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);
    if (!success)
    {
      throw std::exception();
    }

    //Create fragment shader
    GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

    //Attach source code
    glShaderSource(fragmentShaderId, 1, &fragmentShaderSrc, NULL);

    //Compile Shader
    glCompileShader(fragmentShaderId);

    //Check for errors
    glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);
    if (!success)
    {
      throw std::exception();
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Shader Program

    //Create shader program
    programId = glCreateProgram();

    //Attach shader objects
    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);

    //set VAO to correct (first) position
    glBindAttribLocation(programId, 0, "in_Position");
    glBindAttribLocation(programId, 1, "in_Color");

    if (glGetError() != GL_NO_ERROR)
    {
      throw std::exception();
    }

    //Link program
    glLinkProgram(programId);

    //Check for errors
    glGetProgramiv(programId, GL_LINK_STATUS, &success);
    if (!success)
    {
      throw std::exception();
    }

    //Detach and destroy shader objects
    glDetachShader(programId, vertexShaderId);
    glDeleteShader(vertexShaderId);
    glDetachShader(programId, fragmentShaderId);
    glDeleteShader(fragmentShaderId);
  }

  void Renderer::onDisplay()
  {
    shader->setAttribute("", buffer);
    shader->render();

    std::cout << "Renderer::OnDisplay" << std::endl;
    bool quit = false;

    while (!quit)
    {
      SDL_Event event = { 0 };      //Check for inputs

      while (SDL_PollEvent(&event)) //if there was an input
      {
        if (event.type == SDL_QUIT) //if the input was 'close button clicked'
        {
          quit = true;
        }
      }

      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      //Drawing

      //Bind the shader to change the uniform
      glUseProgram(programId);

      //Reset State
      glUseProgram(0);

      //Set clear color and clear screan
      glClearColor(1.0f, 0.0f, 0.0f, 1.0f); //Clear refers to setting the color of untampered with pixels, as opposed to clearing the screen.
      glClear(GL_COLOR_BUFFER_BIT);

      //Tell OpenGL to use the shader program and VAO
      glUseProgram(programId);
      glBindVertexArray(vaoId);

      //Draw 3 vertices
      glDrawArrays(GL_TRIANGLES, 0, 3);

      //Reset state
      glBindVertexArray(0);
      glUseProgram(0);

      //swap openGL buffer with screen buffer
      SDL_GL_SwapWindow(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
  }
}