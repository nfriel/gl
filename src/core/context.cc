#include "context.h"

Context::Context(int width, int height)
{
    this->w = width;
    this->h = height;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    this->window = glfwCreateWindow(this->w, this->h, "gl", nullptr, nullptr);
    if (this->window == nullptr) {
        std::cout << "-- glfwCreateWindow error\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(this->window);
    glfwSetWindowSizeCallback(this->window, resize);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "-- Unable to initialize glad\n";
        glfwTerminate();
        return;
    }
}

bool Context::windowIsOpen()
{
    return !glfwWindowShouldClose(this->window);
}

void Context::clear()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Context::refresh()
{
    glfwPollEvents();
    glfwSwapBuffers(this->window);
}
