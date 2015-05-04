#version 330 core
#extension GL_ARB_explicit_uniform_location : require

in vec4 outColor;
in vec4 outNormal;
out vec4 finalColor;
layout(location = 3) uniform vec4 LightDir1;

void main(void)
{
    finalColor = outColor * clamp(dot(-LightDir1,outNormal),0.2,1.0) ;
}

