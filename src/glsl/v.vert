#version 330 core
layout (location = 0) in vec3 p;
layout (location = 1) in vec2 t;

out vec2 to;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
    gl_Position = proj * view * model * vec4(p, 1.0);
    to = t;
}
