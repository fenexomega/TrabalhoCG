#ifndef GRID_H
#define GRID_H

#include <glm/glm.hpp>
#include "graphics/Mesh.h"

class Grid : public Mesh
{
private:
    glm::vec3 m_pos;
    glm::vec2 m_size;
    GLuint lineNbr;
public:
    Grid(glm::vec3 pos, glm::vec2 size, GLuint lineNbr,
         glm::vec4 color = glm::vec4(1.0f,1.0f,1.0f,1.0f));
    ~Grid();

    // Mesh interface

    // Mesh interface
public:
    void VDraw();
};

#endif // GRID_H
