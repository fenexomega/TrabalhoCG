#include "Box.h"
#include <iostream>
#include <vector>
#define VERTICES 8

Box::Box(glm::vec3 size, glm::vec3 color,glm::vec3 pos)
{
    std::vector<vec3> vertex;
    for(int i = 0; i < 2; ++i)
    {
        vertex.push_back(vec3(-size.x/2,size.y,size.z/2));
        vertex.push_back(vec3(-size.x/2,0,size.z/2));
        vertex.push_back(vec3( size.x/2,0,size.z/2));
        vertex.push_back(vec3( size.x/2,size.y,size.z/2));

        size.z *= -1;
    }

    std::vector<GLuint> elements = {
       //Front
       0,1,2,
       2,3,0,

       //Right
       3,2,6,
       6,7,3,

       //Down
       5,1,2,
       2,6,5,

       //Left
       0,1,5,
       5,4,0,

       //Up
       4,0,3,
       3,7,4,


       //Back
       7,6,5,
       5,4,7





    };

    for(int i = 0; i < VERTICES; ++i)
        m_color.push_back(color);
    setGlThings(vertex,elements);

}

Box::~Box()
{

}

