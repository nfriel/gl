#pragma once

#include "util.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

class Context {
public:
    GLFWwindow *window;

    int w;
    int h;

public:
    Context(int width, int height);

    bool windowIsOpen();
    void clear();
    void refresh();
};
