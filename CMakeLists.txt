cmake_minimum_required(VERSION 3.17)
project(un (your name of Clion progect))

set(CMAKE_CXX_STANDARD 11)


set(GLEW_H /usr/local/Cellar/glew/2.2.0_1/include/GL (your path to GL))
set(GLFW_H /usr/local/Cellar/glfw/3.3.8/include/GLFW (your path to GLFW))
include_directories(${GLEW_H} ${GLFW_H})


set(GLEW_LINK /usr/local/Cellar/glew/2.2.0_1/lib/libGLEW.2.2.dylib (your path))
set(GLFW_LINK  /usr/local/Cellar/glfw/3.3.8/lib/libglfw.3.dylib (your path))
link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})

set(SOURCE_FILES main.cpp cube.h cube_realisation.cpp rotations.cpp solver.cpp visual_cube.cpp)
add_executable(un ${SOURCE_FILES})


if (APPLE)
    target_link_libraries(un (your name of Clion progect) "-framework OpenGL")
    target_link_libraries(un (your name of Clion progect) "-framework GLUT")
endif()

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)


include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(un ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
