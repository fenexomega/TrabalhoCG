#include "Grid.h"

#define PI 3.141516f

#include "utils/Logger.h"

Grid::Grid(glm::vec3 pos, glm::vec2 size, GLuint lineNbr, glm::vec3 color)
    : m_pos(pos),m_size(size),lineNbr(lineNbr)
{
    std::vector<vec3> vertex;
    std::vector<GLuint> elements;
    std::vector<vec3> normals;

    for(float i = -m_size.y*lineNbr/2, e = 0; e <= 2*lineNbr; i += m_size.y, e += 2)
    {
        vertex.push_back(vec3(-(m_size.x*lineNbr)/2,0,i));
        vertex.push_back(vec3((m_size.x*lineNbr)/2,0,i));

        elements.push_back(e);
        elements.push_back(e+1);

        normals.push_back(glm::normalize(vec3(1,1,1)));
        normals.push_back(glm::normalize(vec3(1,1,1)));


    }
    LOG("X = " << color.x << " | " << "Y = " << color.y);
    for(auto i = 0; i < vertex.size(); ++i)
        m_color.push_back(color);
    m_transform->translate(pos);
    setGlThings(vertex,elements,normals,false);
}

Grid::~Grid()
{

}

void Grid::VDraw()
{
    glBindVertexArray(vao);
    glUniform1i(4,m_haveNormals);
    Transform *aux = new Transform;
    *aux = *m_transform;
    m_transform->SendToShader();
    glDrawElements(GL_LINES,m_nbr_elements,GL_UNSIGNED_INT,0);
    m_transform->rotate(90.0f,0,1.0f,0);
    m_transform->SendToShader();
    glDrawElements(GL_LINES,m_nbr_elements,GL_UNSIGNED_INT,0);
    m_transform = aux;
    glBindVertexArray(0);
}
