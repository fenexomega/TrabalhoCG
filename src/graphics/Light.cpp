#include "Light.h"
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include "objects/Box.h"

vec3 Light::dir() const
{
    return m_dir;
}

void Light::setDir(const glm::vec3 &dir)
{
    m_dir = dir;
    glUniform3f(5,dir.x,dir.y,dir.z);

}
Light::Light(glm::vec3 dir) : Mesh()
{
    m_dir = dir;
    glUniform3f(5,dir.x,dir.y,dir.z);
//    glUniform4fv(3,1,&dir[0]);
    m_box = new Box(vec3(0.2f),vec3(1.0f),dir,false);

}

Light::~Light()
{
    delete m_box;
}



void Light::VUpdate()
{
    glUniform3f(5,m_dir.x,m_dir.y,m_dir.z);
    m_box->VUpdate();
}

void Light::VDraw()
{
    m_box->VDraw();
}
