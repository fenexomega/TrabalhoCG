#ifndef SQUARE_H
#define SQUARE_H

#include "graphics/Mesh.h"



class Square : public Mesh
{
private:

public:
    Square(glm::vec2 size, glm::vec4 color = glm::vec4()
            , glm::vec3 pos = glm::vec3());
    ~Square();
};

#endif // SQUARE_H
