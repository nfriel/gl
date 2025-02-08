#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

class Context {
public:
    int sw;
    int sh;

    GLFWwindow *window;

    Context(int w, int h);
    void clear();
    void swap();
    void quit();
};

void resize(GLFWwindow *window, int w, int h);
