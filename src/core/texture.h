#pragma once

#include "glad/glad.h"
#include <string>
#include <iostream>

class Texture {
public:
    unsigned int id;

    Texture(std::string& path);
    void bind();
};
