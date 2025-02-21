#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <string>

class Texture {
private:
    unsigned int texture;

public:
    Texture(std::string path);

    void bind();
};
