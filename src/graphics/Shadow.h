#ifndef SHADOW_H
#define SHADOW_H

#include "Mesh.h"
#include "graphics/Light.h"

class Shadow : public Mesh
{
public:
    Shadow(const Mesh* mesh, vec3 plane, Light l);
    ~Shadow();
};

#endif // SHADOW_H
