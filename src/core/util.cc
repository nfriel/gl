#include "util.h"

void resize(GLFWwindow *w, int x, int y)
{
    glViewport(0, 0, x, y);
    std::cout << "-- Window resized to " << x << "x" << y << "\n";
}

std::string readFile(std::string path)
{
    path = "../src/glsl/" + path;

    std::string str;
    std::string line;

    std::ifstream file(path);

    while (std::getline(file, line)) {
        str += line + "\n";
    }

    return str;
}

void checkErrors(unsigned int shader, std::string type)
{
    int success;
    char infolog[1024];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 1024, NULL, infolog);
        std::cout << infolog;
    }
}
