#include "Light.h"
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include "objects/Box.h"

vec3 Light::pos() const
{
    return m_pos;
}

void Light::setDir(const glm::vec3 &dir)
{
    m_pos = dir;
    glUniform3f(5,dir.x,dir.y,dir.z);

}
Light::Light(glm::vec3 pos, glm::vec3 size) : Mesh()
{
    m_pos = pos;
    glUniform3f(5,pos.x,pos.y,pos.z);
//    glUniform4fv(3,1,&dir[0]);
    m_box = new Box(vec3(0.2,0.2,0.2)*size,vec3(1.0f),pos,false);

}

Light::~Light()
{
    delete m_box;
}



void Light::VUpdate()
{
    glUniform3f(5,m_pos.x,m_pos.y,m_pos.z);
    m_box->VUpdate();
}

void Light::VDraw()
{
    m_box->VDraw();
}
