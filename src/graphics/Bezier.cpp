#include "Bezier.h"


Bezier::Bezier(glm::vec3 ctrl_pts[], int t)
{
    std::vector<glm::vec3> vertex;
    std::vector<GLuint> elements;
/* O CÓDIGO COMENTADO É TENTATIVA PARA FAZER POR MATRIZ. FICOU Ó, UMA BOSTA */
    glm::mat4 bzmat = {
        -1.0f, 3.0f,-3.f,  1.0f,
         3.0f, -6.0f, 3.0f, 0.0f,
        -3.0f, 3.0f, 0.0f, 0.0f,
         1.0f, 0.0f, 0.0f, 0.0f
    };

    vec3 aux;
    glm::vec4 auxx;
    GLuint e = 0;
    float cof = 1.0f/t;
    std::cout << "NUM = " <<cof << std::endl;
    for(float u = 0; u <= 1.0f; u += cof)
    {
        float one_minus_u  = (1-u);
        float one_minus_u2 = one_minus_u*one_minus_u;
        float one_minus_u3 = one_minus_u2*one_minus_u;

        float u2 = u*u;
        float u3 = u2*u;

            glm::mat4 pvec = {ctrl_pts[0][0],ctrl_pts[0][1],ctrl_pts[0][2],1,
                              ctrl_pts[1][0],ctrl_pts[1][1],ctrl_pts[1][2],1,
                              ctrl_pts[2][0],ctrl_pts[2][1],ctrl_pts[2][2],1,
                              ctrl_pts[3][0],ctrl_pts[3][1],ctrl_pts[3][2],1};
            glm::vec4 uvec = { u3,u2,u,1.0f};

//            aux =  (      one_minus_u3 *      ctrl_pts[0]
//                    + 3 * one_minus_u2 * u  * ctrl_pts[1]
//                    + 3 * one_minus_u  * u2 * ctrl_pts[2]
//                    +                    u3 * ctrl_pts[3]);

        auxx = (pvec   * bzmat *  uvec );
        aux = vec3(auxx.x,auxx.y,auxx.z);

        vertex.push_back(aux);
        elements.push_back(e++);
        m_color.push_back(vec3(1,0,1));
    }

    setGlThings(vertex,elements,std::vector<vec3>(),false);
}


void Bezier::VDraw()
{
    m_p->Use();

    glBindVertexArray(vao);
    glUniform1i(4,m_haveNormals);

    m_transform->SendToShader();
    glDrawElements(GL_LINES,m_nbr_elements,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
}
