#include "CatRoll.h"

#include "utils/Logger.h"
#define CLAMP(A,B) (A) > (B) ? (A) : (B)




CatRoll::CatRoll(glm::vec3 *ctrlPoints, int numCtrlPoints, int numPoints )
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
    _spline =  glm::mat4({-1 , 2,-1, 0,
                           3 ,-5, 0, 2,
                          -3 , 4, 1, 0,
                           1 ,-1, 0, 0 })/2.0f;
    //FOR OPENGL
//    _spline = glm::transpose(_spline);

    glm::mat4 pmat;

    float coef = 1.0f/_numPoints;

    for(int k = 0; k < _ctrlPoints.size() - 3; ++k)
    {
        pmat = {_ctrlPoints[k].x,_ctrlPoints[k].y,_ctrlPoints[k].z,1.0f,
                _ctrlPoints[k+1].x,_ctrlPoints[k+1].y,_ctrlPoints[k+1].z,1.0f,
                _ctrlPoints[k+2].x,_ctrlPoints[k+2].y,_ctrlPoints[k+2].z,1.0f,
                _ctrlPoints[k+3].x,_ctrlPoints[k+3].y,_ctrlPoints[k+3].z,1.0f};

        pmat = glm::transpose(pmat);


        for(float u = 0; u < 1.0f; u += coef)
        {
            float u2 = u*u;
            float u3 = u2*u;
            uvec = {u3,u2,u,1.0f};
            point = (uvec * _spline * pmat);

            vertex.push_back(vec3(point.x,point.y,point.z));
            elements.push_back(e++);
            m_color.push_back(glm::vec4(1,0,0,1.0f));

        }

    }

    setGlThings(vertex,elements,std::vector<vec3>(),false);
}

glm::vec3 CatRoll::getPositionAt(float u)
{
    glm::vec4 uvec, point;



    glm::mat4 pmat;

    int k = u;
    u = u - k;

    pmat = {_ctrlPoints[k].x,_ctrlPoints[k].y,_ctrlPoints[k].z,1.0f,
            _ctrlPoints[k+1].x,_ctrlPoints[k+1].y,_ctrlPoints[k+1].z,1.0f,
            _ctrlPoints[k+2].x,_ctrlPoints[k+2].y,_ctrlPoints[k+2].z,1.0f,
            _ctrlPoints[k+3].x,_ctrlPoints[k+3].y,_ctrlPoints[k+3].z,1.0f};

    pmat = glm::transpose(pmat);


    float u2 = u*u;
    float u3 = u2*u;
    uvec = {u3,u2,u,1.0f};
    point = (uvec * _spline * pmat);

    return vec3(point.x,point.y,point.z);


}

glm::vec3 CatRoll::getUpPosition(float u)
{
    glm::vec4 uvec, point;

    glm::mat4 pmat;

    int k = u;
    u = u - k;

    pmat = {_ctrlPoints[k].x,_ctrlPoints[k].y,_ctrlPoints[k].z,1.0f,
            _ctrlPoints[k+1].x,_ctrlPoints[k+1].y,_ctrlPoints[k+1].z,1.0f,
            _ctrlPoints[k+2].x,_ctrlPoints[k+2].y,_ctrlPoints[k+2].z,1.0f,
            _ctrlPoints[k+3].x,_ctrlPoints[k+3].y,_ctrlPoints[k+3].z,1.0f};

    pmat = glm::transpose(pmat);


    uvec = {6.0f*u,2.0f,0.0f,0.0f};
    point = (uvec * _spline * pmat);

    return vec3(point.x,point.y,point.z);
}

glm::vec3 CatRoll::getNextPosition(float u)
{
    glm::vec4 uvec, point;


    glm::mat4 pmat;

    int k = u;
    u = u - k;

    pmat = {_ctrlPoints[k].x,_ctrlPoints[k].y,_ctrlPoints[k].z,1.0f,
            _ctrlPoints[k+1].x,_ctrlPoints[k+1].y,_ctrlPoints[k+1].z,1.0f,
            _ctrlPoints[k+2].x,_ctrlPoints[k+2].y,_ctrlPoints[k+2].z,1.0f,
            _ctrlPoints[k+3].x,_ctrlPoints[k+3].y,_ctrlPoints[k+3].z,1.0f};

    pmat = glm::transpose(pmat);


    float u2 = u*u;
    uvec = {3*u2,2*u,1.0f,0};
    point = (uvec * _spline * pmat);


    return vec3(point.x,point.y,point.z);
}

glm::mat4 CatRoll::getTransformMatrix(float u)
{
    auto t = getPositionAt(u);

    auto z = glm::normalize(-getNextPosition(u));
    auto y = vec3(0,1,0); //glm::normalize(getUpPosition(u));
    auto x = glm::normalize(glm::cross(y,z));
    y = glm::normalize(glm::cross(z,x));


    glm::mat4 mat = {x.x,x.y,x.z,0,
                     y.x,y.y,y.z,0,
                     z.x,z.y,z.z,0,
                     t.x,t.y,t.z,1.0f};
    return mat;
}



int CatRoll::numCtrlPoints()
{
    return _ctrlPoints.size();
}



void CatRoll::VDraw()
{
    m_p->Use();

    glBindVertexArray(vao);
    glUniform1i(4,m_haveNormals);

    m_transform->SendToShader();
    glDrawElements(GL_LINE_STRIP,m_nbr_elements,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
}
