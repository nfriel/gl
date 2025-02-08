#pragma once

#include "glad/glad.h"
#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <iostream>

class Shader {
public:
    Shader(std::string vp, std::string fp);
    void use();
    void setFloat(std::string& name, float value);
    void setInt(std::string& name, int value);
    void setMat4(std::string &name, glm::mat4 value);
private:
    unsigned int vertex;
    unsigned int fragment;
    unsigned int program;
    unsigned int texture;

    std::string load(std::string p);
    void checkErrors(unsigned int shader, std::string type);
};
