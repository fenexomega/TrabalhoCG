#version 330 core
#extension GL_ARB_explicit_uniform_location : require

struct dirLight{
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

};

in vec4 outColor;
in vec3 outNormal;
in vec3 FragPos;

layout(location = 4) uniform int haveNormals;
layout(location = 5) uniform vec3 LightPos;
layout(location = 6) uniform vec3 viewPos;

out vec4 finalColor;
vec3 lightColor = vec3(1.0,1.0,1.0);

float ambientStrength = 0.3;
float specularStrength = 0.5;

void main(void)
{
    if(haveNormals == 1)
    {
      // UTILIZANDO PHONG SHADING

        // AMBIENT
        vec3 ambient = lightColor * ambientStrength;

        // DIFUSE
        vec3 lightDir = normalize(LightPos - FragPos);
        float diff = max(dot(outNormal.xyz,lightDir),0);
        vec3 difuse = lightColor * diff;

        // SPECULAR
        vec3 viewDir = normalize(viewPos - FragPos);
        vec3 reflectDir = reflect(-lightDir,outNormal.xyz);
        float spec = pow(max(dot(viewDir,reflectDir),0.0),128);
        vec3 specular = specularStrength * lightColor * spec;

        vec4 result = vec4(difuse + ambient + specular,1.0);
        finalColor = result*outColor;
        return;
    }
    finalColor = outColor;

}

