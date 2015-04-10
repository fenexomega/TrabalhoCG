#include "Grid.h"

#define PI 3.141516f

Grid::Grid(glm::vec3 pos, glm::vec2 size, GLuint lineNbr)
    : m_pos(pos),m_size(size),lineNbr(lineNbr)
{
    std::vector<float> vertex;
    std::vector<GLuint> elements;

    for(float i = -m_size.y*lineNbr/2, e = 0; e <= 2*lineNbr; i += m_size.y, e += 2)
    {
        vertex.push_back(-m_size.x/2);
        vertex.push_back(0);
        vertex.push_back(i);
        vertex.push_back(m_size.x/2);
        vertex.push_back(0);
        vertex.push_back(i);
        elements.push_back(e);
        elements.push_back(e+1);

    }
    for(auto i = 0; i < vertex.size(); ++i)
        m_color.push_back(glm::vec3(1.0,1.0,1.0));
    m_transform.translate(pos);
    setGlThings(vertex,elements);
}

Grid::~Grid()
{

}

void Grid::VDraw()
{
    glBindVertexArray(vao);
    Transform aux = m_transform;
    m_transform.SendToShader();
    glDrawElements(GL_LINES,m_elements,GL_UNSIGNED_INT,0);
    m_transform.rotate(PI/2.0f,0,1.0f,0);
    m_transform.SendToShader();
    glDrawElements(GL_LINES,m_elements,GL_UNSIGNED_INT,0);
    m_transform = aux;
    glBindVertexArray(0);
}
