#ifndef ARROW_H
#define ARROW_H

#include <glm/glm.hpp>
#include "graphics/Mesh.h"
class Arrow : public Mesh
{
private:
    glm::vec3 m_pos;
    glm::vec3 m_choosenColor;
public:
    Arrow();
    Arrow(glm::vec3 pos, glm::vec3 color, glm::vec4 rot = glm::vec4(0.0f,1.0f,0.0f,0.0f));
    ~Arrow();

    Arrow operator=(Arrow a);

    // Mesh interface
public:
    void VDraw();
};

#endif // ARROW_H
