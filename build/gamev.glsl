#version 330
#extension GL_ARB_explicit_uniform_location : require

layout(location = 0) in vec3  Pos;
layout(location = 1) in vec3 inColor;
layout(location = 0) uniform mat4 model;
layout(location = 1) uniform mat4 view;
layout(location = 2) uniform mat4 proj;
out vec4 outColor;


void main(void)
{
    gl_Position = proj * view *model * vec4(Pos,1.0);
    outColor = vec4(inColor,1.0);
}

