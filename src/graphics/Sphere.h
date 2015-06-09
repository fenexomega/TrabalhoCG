#ifndef SPHERE_H
#define SPHERE_H

#include "graphics/Mesh.h"

class Sphere : public Mesh
{
public:
    Sphere(float r, GLint slices, GLint stacks);

    // Mesh interface
public:
    void VDraw();
};

#endif // SPHERE_H
