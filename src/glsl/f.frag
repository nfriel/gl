#version 330 core
in vec2 to;

out vec4 colorOut;

uniform sampler2D ut;

void main()
{
    colorOut = texture(ut, to);
}
