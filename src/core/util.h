#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <fstream>
#include <iostream>
#include <string>

void resize(GLFWwindow *w, int x, int y);
std::string readFile(std::string path);
void checkErrors(unsigned int shader, std::string type);
