#ifndef TexBOX_H
#define TexBOX_H

#include "graphics/TexMesh.h"

#include <glm/glm.hpp>

class TexBox : public TexMesh
{

public:
    TexBox(glm::vec3 size, glm::vec4 color = glm::vec4(1.0f,1.0f,1.0f,1.0f), glm::vec3 pos = {0,0,0},
        bool haveNormals = true);
    ~TexBox();

    // Mesh interface
public:
    void VUpdate();
    void VDraw();
};

#endif // TexBOX_H
