cmake_minimum_required(VERSION 2.6)
project(SkeyeEngine)

add_library(SkeyeEngine
src/SkeyeEngine/dummy.cpp
)

target_link_libraries(SkeyeEngine SDL2 opengl32 glew32)
add_executable(game
src/game/main.cpp
)

target_link_libraries(game SkeyeEngine) 