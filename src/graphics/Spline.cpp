#include "Spline.h"

#include "utils/Logger.h"
#define CLAMP(A,B) (A) > (B) ? (A) : (B)

Spline::Spline(glm::vec3 *ctrlPoints, int numCtrlPoints, int numPoints )
    : _numPoints(numPoints)
{
    int i = 0;
    while(i < numCtrlPoints)
        _ctrlPoints.push_back(ctrlPoints[i++]);


    std::vector<vec3> vertex;
    std::vector<GLuint> elements;
    int e = 0;
    glm::vec4 point;
    glm::vec4 uvec;
    glm::mat4 bspline =    {-1 , 3,-3, 1,
                             3 ,-6, 3, 0,
                            -3 , 0, 3, 0,
                             1 , 4, 1, 0};
    bspline = bspline/6.0f;

    glm::mat4 pmat;

    float coef = 1.0f/_numPoints;

    for(int k = 0; k < _ctrlPoints.size() - 3; ++k)
    {
        LOG(k);
        pmat = {_ctrlPoints[k].x,_ctrlPoints[k].y,_ctrlPoints[k].z,1.0f,
                _ctrlPoints[k+1].x,_ctrlPoints[k+1].y,_ctrlPoints[k+1].z,1.0f,
                _ctrlPoints[k+2].x,_ctrlPoints[k+2].y,_ctrlPoints[k+2].z,1.0f,
                _ctrlPoints[k+3].x,_ctrlPoints[k+3].y,_ctrlPoints[k+3].z,1.0f};

        for(float u = 0; u < 1.0f; u += coef)
        {
            float u2 = u*u;
            float u3 = u2*u;
            uvec = {u3,u2,u,1.0f};
            point = uvec * bspline * pmat;

            vertex.push_back(vec3(point.x,point.y,point.z));
            elements.push_back(e++);
            m_color.push_back(vec3(1,0,0));

        }

    }

    setGlThings(vertex,elements,std::vector<vec3>(),false);
}



void Spline::VDraw()
{
    m_p->Use();

    glBindVertexArray(vao);
    glUniform1i(4,m_haveNormals);

    m_transform->SendToShader();
    glDrawElements(GL_LINE_STRIP,m_nbr_elements,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
}
