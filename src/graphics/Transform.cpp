#include "Transform.h"

#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>

#define PI 3.141516f
#define TORAD(x) (PI*(x))/180.0f

vec3 &Transform::pos()
{
    return m_pos;
}

void Transform::setPos(const vec3 &pos)
{

    m_model = glm::translate(m_model,pos);
    m_pos = pos;
}

glm::vec3 &Transform::rot()
{

    return m_rot;
}

void Transform::setRot(const vec3 &rot)
{
    m_rot = rot;
    m_model = glm::rotate(m_model,m_rot.x,vec3(1,0,0));
    m_model = glm::rotate(m_model,m_rot.y,vec3(0,1,0));
    m_model = glm::rotate(m_model,m_rot.z,vec3(0,0,1));
}

glm::vec3 &Transform::scale()
{
    return m_scale;
}

void Transform::setScale(const vec3 &scale)
{
    m_model = glm::scale(m_model,scale);
    m_scale = scale;
}


glm::mat4 Transform::getModel() const
{
    return m_model;
}

void Transform::setModel(const glm::mat4 &model)
{
    m_model = model;
}

Transform::Transform(glm::vec3 _m_pos,
                     glm::vec3 _m_rot,
                     glm::vec3 _m_scale) :
    m_pos(_m_pos), m_rot(_m_rot), m_scale(_m_scale)
{

}

Transform Transform::operator=(const Transform &T)
{
    m_model = T.m_model;
    return *this;
}

glm::mat4 Transform::getMatrix()
{
    return m_model;
}

//glm::mat4 Transform::getModel() const
//{
//    glm::mat4 posMx = glm::translate(m_pos);
//    glm::mat4 rotXMx = glm::rotate(m_rot.x,vec3(1,0,0));
//    glm::mat4 rotYMx = glm::rotate(m_rot.y,vec3(0,1,0));
//    glm::mat4 rotZMx = glm::rotate(m_rot.z,vec3(0,0,1));
//    glm::mat4 scaleMx = glm::scale(m_scale);

//    return ;
//}

Transform& Transform::rotate(float angle, float x, float y, float z)
{
    m_rot += TORAD(angle)*vec3(x,y,z);
    m_model = glm::rotate(m_model,TORAD(angle),vec3(x,y,z));
    return *this;
}

Transform& Transform::rotate(float angle, glm::vec3 vec)
{
    m_rot += TORAD(angle)*vec;
    m_model = glm::rotate(m_model,TORAD(angle),vec);
    return *this;
}

Transform& Transform::translate(float x, float y, float z)
{
    m_pos += vec3(x,y,z);
    m_model = glm::translate(m_model,vec3(x,y,z));
    return *this;
}

Transform& Transform::translate(glm::vec3 vec)
{
    m_pos += vec;
    m_model = glm::translate(m_model,vec);
    return *this;
}

Transform& Transform::scale(float x, float y, float z)
{
    m_scale *= vec3(x,y,z);
    m_model = glm::scale(m_model,vec3(x,y,z));
    return *this;
}

Transform& Transform::scale(glm::vec3 vec)
{
    m_scale *= vec;
    m_model = glm::scale(m_model,vec);
    return *this;
}

Transform& Transform::clear()
{
    m_model = glm::mat4();
    m_scale = glm::vec3(1);
    m_pos = glm::vec3(0);
    m_rot = glm::vec3(0);

    return *this;
}

void Transform::SendToShader()
{
    glUniformMatrix4fv(0,1,GL_FALSE,glm::value_ptr(m_model));
}



Transform::~Transform()
{

}

