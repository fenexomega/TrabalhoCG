#ifndef CYLINDER_H
#define CYLINDER_H

#include <graphics/Mesh.h>


class Cylinder : public Mesh
{
public:
    Cylinder(float radius, float height, int slices, int sections);

    // Mesh interface
public:
    void VDraw();
};

#endif // CYLINDER_H
