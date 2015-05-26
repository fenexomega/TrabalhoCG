#include "Bezier.h"


Bezier::Bezier(glm::vec3 control_points[], int t)
{
    std::vector<glm::vec3> vertex;
    std::vector<GLuint> elements;
    vec3 aux;
    GLuint e = 0;
    float cof = 1/(float)t;
    for(float u = 0; u <= 1.0f; u += cof)
    {
        for(int i = 0; i < 3; ++i)
        {
            aux[i] = (pow((1-u),3)*control_points[0][i]
                    + 3*pow((1-u),2)*u*control_points[1][i]
                    + 3*pow((1-u),2)*u*control_points[2][i]
                    + pow(u,3)*control_points[3][i]);
        }
        vertex.push_back(aux);
        elements.push_back(e++);
        m_color.push_back(vec3(1,0,0));
    }

    setGlThings(vertex,elements,std::vector<vec3>(),false);
}


void Bezier::VDraw()
{
    m_p->Use();

    glBindVertexArray(vao);
    glUniform1i(4,m_haveNormals);

    m_transform->SendToShader();
    glDrawElements(GL_LINE_STRIP,m_nbr_elements,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
}
