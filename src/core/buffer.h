#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class Buffer {
private:
    unsigned int vao;
    unsigned int vbo;
    unsigned int ebo;

public:
    Buffer();

    void bind();
};
