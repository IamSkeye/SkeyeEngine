#include "ShaderProgram.h"

namespace Skeye
{
  ShaderProgram::ShaderProgram() {
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
  };

  ShaderProgram::~ShaderProgram() {};

  //Vertex shader source code
  const GLchar *vertexShaderSrc =
    "attribute vec3 in_Position;	                                                " \
    "attribute vec4 in_Color;			                                                " \
    "uniform mat4 in_Model;			                                                  " \
    "uniform mat4 in_View;			                                                  " \
    "uniform mat4 in_Proj;	                                                      " \
    "											                                                        " \
    "varying vec4 ex_Color;				                                                " \
    "											                                                        " \
    "void main()							                                                    " \
    "{                                                                            " \
    "	 gl_Position = in_Proj * in_View * in_Model * vec4(in_Position, 1.0);       " \
    "	 ex_Color = in_Color;			        	                                        " \
    "}							                  		                                        ";  //'in_Position' - For ensuring the shader is linked in the correct position to the VAO[?]
                                                                                     //'in_Color'/'ex_Color' - For interpolating colors between vertex and fragment shaders


  //Fragment shader source code
  const GLchar *fragmentShaderSrc =
    "varying vec4 ex_Color;		  	" \
    "								            	" \
    "void main()			      			" \
    "{							            	" \
    "  gl_FragColor = ex_Color;		" \
    "}						            		";  //For any fragment drawn, use the colour stored in the uniform in_Color.

  void ShaderProgram::setAttribute()
  {

  }
}