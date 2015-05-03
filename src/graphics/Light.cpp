#include "Light.h"
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

vec4 Light::dir() const
{
    return m_dir;
}

void Light::setDir(const vec4 &dir)
{
    m_dir = dir;
    glUniform4fv(3,1,glm::value_ptr(dir));

}
Light::Light(vec4 dir)
{
    m_dir = dir;
    glUniform4fv(3,1,glm::value_ptr(dir));
//    glUniform4fv(3,1,&dir[0]);


}

Light::~Light()
{

}

