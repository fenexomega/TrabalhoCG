#version 330 core
#extension GL_ARB_explicit_uniform_location : require

in vec4 outColor;
in vec4 outNormal;

layout(location = 4) uniform int haveNormals;
layout(location = 3) uniform vec4 LightDir1;
out vec4 finalColor;



void main(void)
{
    if(haveNormals == 1)
    {
        finalColor = outColor * clamp(dot(-LightDir1,outNormal),0.2,1.0) ;

        return;
    }
    finalColor = outColor;

}

