#include "Arrow.h"
#define UNITY 0.025f


Arrow::Arrow()
{

}

Arrow::Arrow(glm::vec3 pos, glm::vec3 color,
             glm::vec4 rot)
    : m_pos(pos),m_choosenColor(color)
{
    std::vector<vec3> vertex = {
        vec3(-UNITY,UNITY*10,-UNITY),
        vec3(-UNITY,UNITY*10,UNITY),
         vec3(UNITY,UNITY*10,UNITY),
         vec3(UNITY,UNITY*10,-UNITY),

        vec3(0.0f,3*UNITY+UNITY*10,0.0f),

        //LINHA
        vec3(0.0f,UNITY*10,0.0f),
        vec3(0.0f,0.0f,0.0f),
    };


    std::vector<GLuint> elements =
    {
        0,1,2,
        2,3,0,

        0,1,4,
        1,2,4,
        2,3,4,
        3,0,4,

        5,6,7
    };

    for(auto i = 0; i < vertices; ++i)
        m_color.push_back(color);

    setGlThings(vertex,elements,std::vector<vec3>(),false);

//    if(rot.x != 0.0f)
    m_transform->translate(pos);

    m_transform->rotate(rot.x,glm::vec3(rot.y,rot.z,rot.w));

}

Arrow::~Arrow()
{

}

Arrow Arrow::operator=(Arrow a)
{
    m_pos = a.m_pos;
    m_choosenColor = a.m_choosenColor;
    this->operator =(a);
    return *this;
}



void Arrow::VDraw()
{

    glBindVertexArray(vao);
    glUniform1i(4,m_haveNormals);

    //  glDrawArrays(GL_TRIANGLES,0,vertices);
    m_transform->SendToShader();

    glDrawElements(GL_TRIANGLES,m_nbr_elements - 2,GL_UNSIGNED_INT,0);
    glDrawElements(GL_LINES,m_nbr_elements,GL_UNSIGNED_INT,0);



    glBindVertexArray(0);
}
