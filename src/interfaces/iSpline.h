#ifndef ISPLINE
#define ISPLINE

#include <glm/glm.hpp>
using glm::vec3;

class iSpline
{
public:
    virtual vec3 getPositionAt(float u) = 0;
    virtual vec3 getUpPosition(float u) = 0;
    virtual vec3 getNextPosition(float u) = 0;
    virtual glm::mat4 getTransformMatrix(float u) = 0;
    virtual int numCtrlPoints() = 0;
};

#endif // ISPLINE

