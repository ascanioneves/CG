cmake_minimum_required(VERSION 3.20)
project(cg)

set(CMAKE_CXX_STANDARD 14)

add_executable(cg main.cpp)
target_link_libraries(cg -lOpenGL32 -lglfw3dll -lfreeGLUT -lglu32)