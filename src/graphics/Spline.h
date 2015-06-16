#ifndef SPLINE_H
#define SPLINE_H


#include "Mesh.h"
#include <vector>
#include <glm/glm.hpp>

using glm::vec3;


class Spline : public Mesh
{
private:
    std::vector<vec3> _ctrlPoints;
    int _numPoints;

public:
    Spline(vec3 * ctrlPoints, int numCtrlPoints, int numPoints);
    vec3 getPositionAt(float u);

    int numCtrlPoints();
    // Mesh interface
public:
    void VDraw();
};

#endif // SPLINE_H
