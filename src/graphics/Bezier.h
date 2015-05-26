#ifndef BEZIER_H
#define BEZIER_H

#include "Mesh.h"


class Bezier : public Mesh
{
public:
    Bezier(glm::vec3 control_points[4],int t );

    // Mesh interface
public:
    void VDraw();
};

#endif // BEZIER_H
