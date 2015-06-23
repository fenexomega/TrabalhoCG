#version 330 core
#extension GL_ARB_explicit_uniform_location : require

in vec4 outColor;
in vec4 outNormal;
in vec3 FragPos;
in vec2 TexCoords;

layout(location = 4) uniform int haveNormals;
layout(location = 3) uniform vec4 LightDir1;
layout(location = 5) uniform vec3 viewPos;

out vec4 finalColor;
vec3 lightColor = vec3(1.0,1.0,1.0);


float specularStrength = 0.5f;

void main(void)
{
    vec3 lightDir = normalize(LightDir1.xyz - FragPos);
    float diff = max(dot(outNormal.xyz,lightDir),0);
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir,outNormal.xyz);
    float spec = pow(max(dot(viewDir,reflectDir),0.0),64);

    if(haveNormals == 1)
    {
      // UTILIZANDO PHONG SHADING
        vec3 ambient = lightColor * 0.3;
        vec3 difuse = lightColor * diff;
        vec3 specular = lightColor * spec;
        vec4 result = vec4(difuse + ambient + specular,1.0);
        finalColor = result*outColor;
        return;
    }
    finalColor = outColor;

}

