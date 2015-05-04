#include "CoordinateArrows.h"

#include "objects/Arrow.h"
#define PI 3.141516f

CoordinateArrows::CoordinateArrows(glm::vec3 pos)
{
    m_meshes.push_back(new Arrow(pos,vec3(1.0f,0.0f,0.0f)));
    m_meshes.push_back(new Arrow(pos,vec3(0.0f,1.0f,0.0f),
                                 vec4(-90.0f,0,0,1.0f)));
    m_meshes.push_back(new Arrow(pos,
                                 vec3(0.0f,0.0f,1.0f),
                                  vec4(90.0f,1.0f,0,0.0f)));


}

CoordinateArrows::~CoordinateArrows()
{
    for(Mesh* m : m_meshes)
        delete m;
}

void CoordinateArrows::setTransform(Transform *trans)
{
    this->m_transform = trans;
    for(Mesh* m : m_meshes)
        m->setTransform(trans);
}




void CoordinateArrows::VUpdate()
{
    //TODO update model matrix

}

void CoordinateArrows::VDraw()
{
    for(Mesh* m : m_meshes)
        m->VDraw();
}
