cmake_minimum_required(VERSION 3.30)
project(gl VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glm)

add_executable(
    gl
    vendor/glad/src/glad.c
    src/main.cc
    src/core/buffer.cc
    src/core/context.cc
    src/core/shader.cc
    src/core/texture.cc
    src/core/util.cc
)

target_include_directories(gl PUBLIC
    vendor/glad/include
    vendor/stb)

target_link_libraries(gl PUBLIC glfw glm::glm OpenGL::GL)
