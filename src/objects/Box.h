#ifndef BOX_H
#define BOX_H

#include "graphics/Mesh.h"

#include <glm/glm.hpp>

class Box : public Mesh
{

public:
    Box(glm::vec3 size,glm::vec3 color ,glm::vec3 pos = {0,0,0},
        bool haveNormals = true);
    ~Box();

    // Mesh interface
public:
    void VUpdate();
    void VDraw();
};

#endif // BOX_H
