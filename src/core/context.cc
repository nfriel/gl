#include "context.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

Context::Context(int w, int h)
{
    sw = w;
    sh = h;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(sw, sh, "gl", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "-- glfwCreateWindow error\n";
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
    glfwSetWindowSizeCallback(window, resize);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "-- glad init error\n";
            glfwTerminate();
            return;
    }

    glEnable(GL_DEPTH_TEST);
}

void Context::clear()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Context::swap()
{
    glfwPollEvents();
    glfwSwapBuffers(window);
}

void Context::quit()
{
    glfwTerminate();
}

void resize(GLFWwindow *window, int w, int h)
{
    glViewport(0, 0, w, h);
    std::cout << "-- window resized to "
        << w << "x" << h << "\n";
}
