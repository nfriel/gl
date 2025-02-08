#pragma once

#include "glad/glad.h"

class Buffer {
public:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int TBO;
    unsigned int EBO;

    Buffer();
    void bind();
};
