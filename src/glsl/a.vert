#version 330 core
layout (location = 0) in vec3 vertex;
layout (location = 1) in vec2 texturecoord;
out vec2 tcoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
    gl_Position = proj * view * model * vec4(vertex, 1.0);
    tcoord = texturecoord;
}
