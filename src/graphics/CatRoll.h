#ifndef CATROLL_H
#define CATROLL_H


#include "Mesh.h"
#include <vector>
#include <glm/glm.hpp>
#include <interfaces/iSpline.h>

using glm::vec3;


class CatRoll : public Mesh, public iSpline
{
private:
    std::vector<vec3> _ctrlPoints;
    int _numPoints;
    glm::mat4 _spline;

public:
    CatRoll(vec3 * ctrlPoints, int numCtrlPoints, int numPoints);
    vec3 getPositionAt(float u);
    vec3 getUpPosition(float u);
    vec3 getNextPosition(float u);
    glm::mat4 getTransformMatrix(float u);
    int numCtrlPoints();
    // Mesh interface
public:
    void VDraw();
};

#endif // CATROLL_H
