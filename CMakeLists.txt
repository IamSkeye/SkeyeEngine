cmake_minimum_required(VERSION 2.6)
project(SkeyeEngine)

include_directories(
src
)

add_library(SkeyeEngine
src/SkeyeEngine/Skeye.h
src/SkeyeEngine/NonCopyable.h
src/SkeyeEngine/Core.h
src/SkeyeEngine/Entity.h
src/SkeyeEngine/Component.h
src/SkeyeEngine/Keyboard.h
src/SkeyeEngine/Environment.h
src/SkeyeEngine/Exception.h
src/SkeyeEngine/Renderer.h
src/SkeyeEngine/ShaderProgram.h
src/SkeyeEngine/Window.h
src/SkeyeEngine/Transform.h
src/SkeyeEngine/Camera.h
src/SkeyeEngine/Mesh.h
src/SkeyeEngine/stb_image.h
src/SkeyeEngine/Core.cpp
src/SkeyeEngine/Entity.cpp
src/SkeyeEngine/Component.cpp
src/SkeyeEngine/Keyboard.cpp
src/SkeyeEngine/Environment.cpp
src/SkeyeEngine/Exception.cpp
src/SkeyeEngine/Renderer.cpp
src/SkeyeEngine/ShaderProgram.cpp
src/SkeyeEngine/Window.cpp
src/SkeyeEngine/Transform.cpp
src/SkeyeEngine/Camera.cpp
src/SkeyeEngine/Mesh.cpp
)

add_library(rend
src/rend/Buffer.h
src/rend/Context.h
src/rend/Exception.h
src/rend/mathutil.h
src/rend/Mesh.h
src/rend/rend.h
src/rend/RenderTexture.h
src/rend/Shader.h
src/rend/Texture.h
src/rend/TextureAdapter.h
src/rend/Util.h
src/rend/Buffer.cpp
src/rend/Context.cpp
src/rend/Exception.cpp
src/rend/Mesh.cpp
src/rend/RenderTexture.cpp
src/rend/Shader.cpp
src/rend/Texture.cpp
src/rend/Util.cpp
)

target_link_libraries(SkeyeEngine SDL2 rend)

if(MSVC)
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()

add_executable(game
src/game/TestScreen.h
src/game/main.cpp
src/game/TestScreen.cpp
)

target_link_libraries(game SkeyeEngine) 