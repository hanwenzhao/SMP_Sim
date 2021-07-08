cmake_minimum_required(VERSION 3.16)
project(SMP_Sim)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/extern/glad/include)
include_directories(${PROJECT_SOURCE_DIR}/extern/glm)
include_directories(${PROJECT_SOURCE_DIR}/extern/stb)

file(GLOB SOURCE_FILES main.cpp include/shader.h include/camera.h extern/stb/stb_image.h extern/glad/src/glad.c)

add_executable(SMP_Sim ${SOURCE_FILES})

target_link_libraries(SMP_Sim glfw ${CMAKE_DL_LIBS})