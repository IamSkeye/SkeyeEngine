cmake_minimum_required(VERSION 2.6)
project(SkeyeEngine)

include_directories(src)

add_library(SkeyeEngine
src/SkeyeEngine/Core.h
src/SkeyeEngine/Entity.h
src/SkeyeEngine/Component.h
src/SkeyeEngine/Keyboard.h
src/SkeyeEngine/Environment.h
src/SkeyeEngine/Core.cpp
src/SkeyeEngine/Entity.cpp
src/SkeyeEngine/Component.cpp
src/SkeyeEngine/Keyboard.cpp
src/SkeyeEngine/Environment.cpp
)

target_link_libraries(SkeyeEngine SDL2 opengl32 glew32)
add_executable(game
src/game/main.cpp

)

target_link_libraries(game SkeyeEngine) 