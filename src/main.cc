#include "core/context.h"
#include "core/shader.h"
#include "core/buffer.h"
#include "core/texture.h"

#include "glad/glad.h"
#include "glm/glm.hpp"

std::string p = "img.png";

int main()
{
    Context context(720, 480);
    Shader shader("a.vert", "a.frag");
    Texture texture(p);
    Buffer buffer;

    std::string tp = "img.png";

    while (!glfwWindowShouldClose(context.window)) {
        context.clear();

        shader.use();
        buffer.bind();
        texture.bind();

        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 proj = glm::mat4(1.0f);
        glm::mat4 rot = glm::mat4(1.0f);

        std::string m = "model";
        std::string v = "view";
        std::string p = "proj";

        model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
        view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        proj = glm::perspective(glm::radians(45.0f), (float)context.sw / (float)context.sh, 0.1f, 100.0f);

        shader.setMat4(m, model);
        shader.setMat4(v, view);
        shader.setMat4(p, proj);

        glDrawArrays(GL_TRIANGLES, 0, 36);
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        context.swap();
    }

    return 0;
}
