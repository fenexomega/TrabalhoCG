#include "Square.h"

#include <vector>

Square::Square(glm::vec2 size, glm::vec3 color, glm::vec3 pos)
{
    std::vector<vec3> vertex = {


        vec3(-size.x/2,size.y/2,0),
        vec3(-size.x/2,-size.y/2,0),
         vec3(size.x/2,-size.y/2,0),
         vec3(size.x/2,size.y/2,0)
    };

    std::vector<GLuint> elements = {
        0,1,2,
        2,3,0
    };

    for(int i = 0; i < vertex.size(); ++i)
    {
        m_color.push_back(color);
    }

    setGlThings(vertex,elements);
    m_transform->translate(pos);
}


Square::~Square()
{

}

