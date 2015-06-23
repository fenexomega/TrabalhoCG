#ifndef LIGHT_H
#define LIGHT_H

#include "Mesh.h"

#include <glm/glm.hpp>
using glm::vec4;
class Box;

class Light : public Mesh
{
private:
    vec3 m_dir;
    Box * m_box;
public:
    Light(vec3 dir);
    ~Light();
    vec3 dir() const;
    void setDir(const vec3 &dir);

    // Mesh interface
public:
    void VUpdate();
    void VDraw();
};

#endif // LIGHT_H
