cmake_minimum_required (VERSION 2.6)
project (self_gl)

find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

#   Add sub directory to build first
add_subdirectory( lib )

#   Add executable file
add_executable( test_gl test_gl.c++ )

#   Link lib
target_link_libraries( test_gl GraphicEngines ImageConstructor glfw GLEW::GLEW )