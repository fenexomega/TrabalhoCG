#ifndef LIGHT_H
#define LIGHT_H

#include "Mesh.h"

#include <glm/glm.hpp>
using glm::vec4;
class Box;

class Light : public Mesh
{
private:
    vec3 m_pos;
    Box * m_box;
public:
    Light(vec3 pos, vec3 size = vec3(1.0f,1.0f,1.0f));
    ~Light();
    vec3 pos() const;
    void setDir(const vec3 &pos);

    // Mesh interface
public:
    void VUpdate();
    void VDraw();
};

#endif // LIGHT_H
