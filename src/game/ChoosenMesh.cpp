#include "ChoosenMesh.h"

#include "graphics/Mesh.h"
#include "utils/Logger.h"

ChoosenMesh::ChoosenMesh()
{
    m_oldMesh = nullptr;
}

void ChoosenMesh::Update(Mesh *mesh, int i)
{
    if(m_oldMesh != mesh)
    {
        mesh->changeColor(vec3(1.0f,1.0f,1.0f));
        if(m_oldMesh )
            m_oldMesh->changeColor(vec3(1.0f,1.0f,1.0f),true);
        m_oldMesh = mesh;
        LOG("Done " << i);
    }
}

ChoosenMesh::~ChoosenMesh()
{

}
