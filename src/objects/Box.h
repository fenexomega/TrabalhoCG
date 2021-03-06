#ifndef BOX_H
#define BOX_H

#include "graphics/Mesh.h"

#include <glm/glm.hpp>

class Box : public Mesh
{

public:
    Box(glm::vec3 size, glm::vec4 color = glm::vec4(1.0f,1.0f,1.0f,1.0f), glm::vec3 pos = {0,0,0},
        bool haveNormals = true);
    ~Box();

    // Mesh interface
public:
    void VDraw();
};

#endif // BOX_H
