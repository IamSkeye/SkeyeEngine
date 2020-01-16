#include "ShaderProgram.h"

namespace Skeye
{
  ShaderProgram::ShaderProgram() {};
  ShaderProgram::~ShaderProgram() {};

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



}