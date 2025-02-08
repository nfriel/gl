cmake_minimum_required(VERSION 3.30)
project(gl VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(glexe
    src/main.cc
    src/core/context.cc
    src/core/shader.cc
    src/core/texture.cc
    src/core/buffer.cc
    vendor/glad/src/glad.c)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glm)

target_include_directories(glexe PUBLIC
    vendor/glad/include
    vendor/stb)

target_link_libraries(glexe PUBLIC
    glfw
    glm::glm)
