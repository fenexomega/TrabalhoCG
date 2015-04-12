#ifndef COORDINATEARROWS_H
#define COORDINATEARROWS_H

#include "graphics/Mesh.h"

#include <glm/glm.hpp>
#include <vector>
using glm::vec3;
using glm::vec4;

class CoordinateArrows : public Mesh
{
protected:
    std::vector<Mesh*> m_meshes;
public:
    CoordinateArrows(vec3 pos);
    ~CoordinateArrows();
    void setTransform(const Transform &trans);
    // Mesh interface
public:
    void VUpdate();
    void VDraw();
};

#endif // COORDINATEARROWS_H
