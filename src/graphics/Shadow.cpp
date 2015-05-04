#include "Shadow.h"
#include <glm/gtc/matrix_transform.hpp>

Shadow::Shadow(const Mesh *mesh, glm::vec3 plane,
               Light l)
{
    //    glm::mat4 transf ;
    setTransform(mesh->transform());
    //    transf = glm::translate(transf,glm::vec3(0.0f,2.0f,0.0f));

    m_vertex;

    vec4 aux;
    for(auto i : mesh->vertex())
    {
        aux =  vec4(i.x,
                    i.y,
                    i.z,1.0f) ;
        m_vertex.push_back(
                    vec3(aux.x,aux.y,aux.z));
    }
    for(int i = 0; i < m_vertex.size(); ++i)
    {
        m_color.push_back(vec3(1.0f,0.0f,0.0f));
    }
    setGlThings(m_vertex,mesh->elements());

}

Shadow::~Shadow()
{

}

