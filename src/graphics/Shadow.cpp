#include "Shadow.h"
#include <glm/gtc/matrix_transform.hpp>

Shadow::Shadow( Mesh *mesh, glm::vec3 plane,
               Light l)
{
    //    glm::mat4 transf ;
//    setTransform(mesh->transform());
    //    transf = glm::translate(transf,glm::vec3(0.0f,2.0f,0.0f));

    vec3 aux2 = mesh->transform()->pos();
    aux2.y = 0;
    m_transform->setPos(aux2);
    m_transform->setRot(mesh->transform()->rot());
    m_transform->setScale(mesh->transform()->scale());

    m_mesh = mesh;
    vec4 aux;
    for(auto i : mesh->vertex())
    {
        aux =  vec4(i.x,
                    i.y,
                    i.z,1.0f) ;
        m_vertex.push_back(
                    vec3(aux.x,0.0f,aux.z));
    }
    for(uint i = 0; i < m_vertex.size(); ++i)
    {
        m_color.push_back(vec3(0.0f,0.0f,0.0f));
    }
    setGlThings(m_vertex,mesh->elements(),mesh->normals());

}

Shadow::~Shadow()
{

}



void Shadow::VUpdate()
{
    vec3 aux2 = m_mesh->transform()->pos();
    aux2.y = 0;
    m_transform->clear();
    m_transform->setPos(aux2);
    vec3 rot_aux = m_mesh->transform()->rot();
    rot_aux.x = 0;
    rot_aux.z = 0;
    m_transform->setRot(rot_aux);
    m_transform->setScale(m_mesh->transform()->scale());
}
