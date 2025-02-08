#include "shader.h"

// Public
Shader::Shader(std::string vp, std::string fp)
{
    std::string vtemp = load(vp);
    std::string ftemp = load(fp);
    const char *vs = vtemp.c_str();
    const char *fs = ftemp.c_str();

    program = glCreateProgram();
    vertex = glCreateShader(GL_VERTEX_SHADER);
    fragment = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertex, 1, &vs, nullptr);
    glShaderSource(fragment, 1, &fs, nullptr);

    glCompileShader(vertex);
    glCompileShader(fragment);

    checkErrors(vertex, "vertex");
    checkErrors(fragment, "fragment");

    glAttachShader(program, vertex);
    glAttachShader(program, fragment);

    glLinkProgram(program);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use()
{
    glUseProgram(program);
}

void Shader::setFloat(std::string& name, float value)
{
    glUniform1f(glGetUniformLocation(program, name.c_str()), value);
}

void Shader::setInt(std::string& name, int value)
{
    glUniform1i(glGetUniformLocation(program, name.c_str()), value);
}

void Shader::setMat4(std::string& name, glm::mat4 value)
{
    glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

// Private
std::string Shader::load(std::string p)
{
    std::string path = "../src/glsl/" + p;

    std::string str;
    std::string line;
    std::fstream file(path);

    while (std::getline(file, line)) {
        str += line + "\n";
    }

    return str;
}

void Shader::checkErrors(unsigned int shader, std::string type)
{
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char info[1024];
        glGetShaderInfoLog(shader, 1024, nullptr, info);
        std::cout << "-- "<< type << " shader compilation failed\n";
        std::cout << info << "\n";
    }
}


