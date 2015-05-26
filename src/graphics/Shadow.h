#ifndef SHADOW_H
#define SHADOW_H

#include "Mesh.h"
#include "graphics/Light.h"

class Shadow : public Mesh
{
private:
    Mesh* m_mesh;
public:
    Shadow(Mesh* mesh, vec3 plane, Light l);
    ~Shadow();

    // Mesh interface
public:
    void VUpdate();
};

#endif // SHADOW_H
