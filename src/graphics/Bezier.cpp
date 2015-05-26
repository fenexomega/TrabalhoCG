#include "Bezier.h"


Bezier::Bezier(glm::vec3 ctrl_pts[], int t)
{
    std::vector<glm::vec3> vertex;
    std::vector<GLuint> elements;
/* O CÓDIGO COMENTADO É TENTATIVA PARA FAZER POR MATRIZ. FICOU Ó, UMA BOSTA */
//    glm::mat4 bzmat = {
//        -1.0f, 3.0f,-3.f,  1.0f,
//         3.0f, 6.0f, 3.0f, 0.0f,
//        -3.0f, 3.0f, 0.0f, 0.0f,
//         1.0f, 0.0f, 0.0f, 0.0f
//    };

    vec3 aux;
    GLuint e = 0;
    float cof = 1/(float)t;
    for(float u = 0; u <= 1.0f; u += cof)
    {
//        float u2 = u*u;
//        float u3 = u2*u;
        for(int i = 0; i < 3; ++i)
        {
//            glm::mat4 pvec = {ctrl_pts[0][0],ctrl_pts[0][1],ctrl_pts[0][2],0,
//                              ctrl_pts[1][0],ctrl_pts[1][1],ctrl_pts[1][2],0,
//                              ctrl_pts[2][0],ctrl_pts[2][1],ctrl_pts[2][2],0,
//                              ctrl_pts[3][0],ctrl_pts[3][1],ctrl_pts[3][2],0};
//            glm::vec4 uvec = { u3,u2,u,1.0f};

            aux[i] = (pow((1-u),3)*ctrl_pts[0][i]
                    + 3*pow((1-u),2)*u*ctrl_pts[1][i]
                    + 3*pow((1-u),2)*u*ctrl_pts[2][i]
                    + pow(u,3)*ctrl_pts[3][i]);
//            aux[i] = (glm::transpose(pvec) *  bzmat *  uvec )[i];
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
