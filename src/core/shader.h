#pragma once

#include "util.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <string>
#include <iostream>

class Shader {
private:
    unsigned int program;
    unsigned int vert;
    unsigned int frag;

public:
    Shader(std::string vpath, std::string fpath);
    ~Shader();

    void use();
    void setInt(std::string name, int value);
    void setFloat(std::string name, float value);
    void setMat4(std::string name, glm::mat4 value);
};
