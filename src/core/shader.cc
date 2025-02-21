#include "shader.h"

Shader::Shader(std::string vpath, std::string fpath)
{
    std::string v = readFile(vpath);
    std::string f = readFile(fpath);
    const char *vs = v.c_str();
    const char *fs = f.c_str();

    this->program = glCreateProgram();
    this->vert = glCreateShader(GL_VERTEX_SHADER);
    this->frag = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(this->vert, 1, &vs, NULL);
    glShaderSource(this->frag, 1, &fs, NULL);

    glCompileShader(this->vert);
    glCompileShader(this->frag);

    checkErrors(this->vert, "vertex");
    checkErrors(this->frag, "fragment");

    glAttachShader(this->program, this->vert);
    glAttachShader(this->program, this->frag);

    glLinkProgram(this->program);

    glDeleteShader(this->vert);
    glDeleteShader(this->frag);
}

Shader::~Shader()
{
    glDeleteProgram(this->program);
}

void Shader::setInt(std::string name, int value)
{
    const char *n = name.c_str();
    glUniform1i(glGetUniformLocation(this->program, n), value);
}

void Shader::setFloat(std::string name, float value)
{
    const char *n = name.c_str();
    glUniform1f(glGetUniformLocation(this->program, n), value);
}

void Shader::setMat4(std::string name, glm::mat4 value)
{
    const char *n = name.c_str();
    glUniformMatrix4fv(glGetUniformLocation(this->program, n), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::use()
{
    glUseProgram(this->program);
}
