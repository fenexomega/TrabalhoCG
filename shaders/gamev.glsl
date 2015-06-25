#version 330 core
#extension GL_ARB_explicit_uniform_location : require


layout(location = 0) in vec3  Pos;
layout(location = 1) in vec4 inColor;
layout(location = 2) in vec3 normal;
layout(location = 3) in vec2 texCoord;

layout(location = 0) uniform mat4 model;
layout(location = 1) uniform mat4 view;
layout(location = 2) uniform mat4 proj;
out vec4 outColor;
out vec3 outNormal;
out vec3 FragPos;
out vec2 TexCoord;


void main(void)
{
    outNormal   =   normalize(mat3(transpose(inverse(model)))*normal);
    FragPos     =   vec3(model * vec4(Pos,1.0));
    outColor    =   inColor;
    TexCoord    =   texCoord;
    gl_Position =   proj * view * model * vec4(Pos,1.0);

}

