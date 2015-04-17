#version 330 core

in vec4 outColor;
in vec4 outNormal;
out vec4 finalColor;

void main(void)
{
    vec4 LightDir1 = normalize(vec4(-1,-1,-1,0));

    finalColor = outColor * clamp(dot(LightDir1,outNormal),0.2,1.0) ;
}

