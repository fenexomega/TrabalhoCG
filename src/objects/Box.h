#ifndef BOX_H
#define BOX_H

#include "graphics/Mesh.h"

#include <glm/glm.hpp>

class Box : public Mesh
{
public:
    Box(glm::vec3 size,glm::vec3 color = {1.0f,1.0f,1.0f},glm::vec3 pos = {0,0,0},
        bool haveNormals = true);
    ~Box();
};

#endif // BOX_H
