#include "core/buffer.h"
#include "core/context.h"
#include "core/shader.h"
#include "core/texture.h"

#include "glm/glm.hpp"

glm::vec3 cubePositions[] = {
    glm::vec3( 0.0f,  0.0f,  0.0f),
    glm::vec3( 2.0f,  5.0f, -15.0f),
    glm::vec3(-1.5f, -2.2f, -2.5f),
    glm::vec3(-3.8f, -2.0f, -12.3f),
    glm::vec3( 2.4f, -0.4f, -3.5f),
    glm::vec3(-1.7f,  3.0f, -7.5f),
    glm::vec3( 1.3f, -2.0f, -2.5f),
    glm::vec3( 1.5f,  2.0f, -2.5f),
    glm::vec3( 1.5f,  0.2f, -1.5f),
    glm::vec3(-1.3f,  1.0f, -1.5f)
};

int main()
{
    Context ctx(800, 800);
    Buffer buf;
    Texture face("img.png");
    Shader shader("v.vert", "f.frag");

    while (ctx.windowIsOpen()) {
        ctx.clear();

        glm::mat4 view  = glm::mat4(1.0f);
        glm::mat4 proj  = glm::mat4(1.0f);

        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -6.0f));
        proj = glm::perspective(glm::radians(45.0f), float(ctx.w) / float(ctx.h), 0.1f, 100.0f);

        shader.setMat4("view", view);
        shader.setMat4("proj", proj);

        buf.bind();
        face.bind();
        shader.use();

        // Central cube
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::rotate(model, float(glfwGetTime() * glm::radians(30.0f)), glm::vec3(0.0f, 1.0f, 0.0f));
        shader.setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // Orbiting cube
        model = glm::mat4(1.0f);
        model = glm::rotate(model, float(glfwGetTime() * glm::radians(100.0f)), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f));
        shader.setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        ctx.refresh();
    }
}
