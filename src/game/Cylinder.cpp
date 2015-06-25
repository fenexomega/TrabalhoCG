#include "Cylinder.h"

#include <vector>

using std::vector;
using glm::vec3;

#include "utils/Logger.h"

Cylinder::Cylinder(float radius, float height, int slices, int sections)
{
    static float pi = 3.1416f;
    vector<vec3> vertex;
    vector<GLuint> elements;
    GLuint e = 0;
    for(float i = 0; i < 2*pi; i += 2*pi/slices )
    {
        vertex.push_back(vec3(radius*cos(i),radius*sin(i),0));
        elements.push_back(e++);
        m_color.push_back(glm::vec4(0,1,1.0f,1.0f));

    }
    vertex.push_back(vec3(radius*cos(2*pi),radius*sin(2*pi),0));
    elements.push_back(e);
    m_color.push_back(glm::vec4(0,1,1.0f,1.0f));

    setGlThings(vertex,elements,vector<vec3>(),false);
}



void Cylinder::VDraw()
{
    m_p->Use();

    glBindVertexArray(vao);
    glUniform1i(4,m_haveNormals);

    m_transform->SendToShader();
    glDrawElements(GL_LINE_STRIP,m_nbr_elements,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
}
