#include "Box.h"
#include <iostream>
#include <vector>
#define VERTICES 8

Box::Box(glm::vec3 size, glm::vec3 color, glm::vec3 pos, bool haveNormals)
{


    std::vector<vec3> vertex = {
        vec3(-0.5f, -0.5f, -0.5f),
        vec3( 0.5f, -0.5f, -0.5f),
        vec3( 0.5f,  0.5f, -0.5f),
        vec3( 0.5f,  0.5f, -0.5f),
        vec3(-0.5f,  0.5f, -0.5f),
        vec3(-0.5f, -0.5f, -0.5f),

        vec3(-0.5f, -0.5f,  0.5f),
        vec3( 0.5f, -0.5f,  0.5f),
        vec3( 0.5f,  0.5f,  0.5f),
        vec3( 0.5f,  0.5f,  0.5f),
        vec3(-0.5f,  0.5f,  0.5f),
        vec3(-0.5f, -0.5f,  0.5f),

        vec3(-0.5f,  0.5f,  0.5f),
        vec3(-0.5f,  0.5f, -0.5f),
        vec3(-0.5f, -0.5f, -0.5f),
        vec3(-0.5f, -0.5f, -0.5f),
        vec3(-0.5f, -0.5f,  0.5f),
        vec3(-0.5f,  0.5f,  0.5f),

        vec3( 0.5f,  0.5f,  0.5f),
        vec3( 0.5f,  0.5f, -0.5f),
        vec3( 0.5f, -0.5f, -0.5f),
        vec3( 0.5f, -0.5f, -0.5f),
        vec3( 0.5f, -0.5f,  0.5f),
        vec3( 0.5f,  0.5f,  0.5f),

        vec3(-0.5f, -0.5f, -0.5f),
        vec3( 0.5f, -0.5f, -0.5f),
        vec3( 0.5f, -0.5f,  0.5f),
        vec3( 0.5f, -0.5f,  0.5f),
        vec3(-0.5f, -0.5f,  0.5f),
        vec3(-0.5f, -0.5f, -0.5f),

        vec3(-0.5f,  0.5f, -0.5f),
        vec3( 0.5f,  0.5f, -0.5f),
        vec3( 0.5f,  0.5f,  0.5f),
        vec3( 0.5f,  0.5f,  0.5f),
        vec3(-0.5f,  0.5f,  0.5f),
        vec3(-0.5f,  0.5f, -0.5f)
    };

    std::vector<vec3> normals = {
        vec3(0.0f,  0.0f, -1.0f),
        vec3(0.0f,  0.0f, -1.0f),
        vec3(0.0f,  0.0f, -1.0f),
        vec3(0.0f,  0.0f, -1.0f),
        vec3(0.0f,  0.0f, -1.0f),
        vec3(0.0f,  0.0f, -1.0f),

        vec3(0.0f,  0.0f,  1.0f),
        vec3(0.0f,  0.0f,  1.0f),
        vec3(0.0f,  0.0f,  1.0f),
        vec3(0.0f,  0.0f,  1.0f),
        vec3(0.0f,  0.0f,  1.0f),
        vec3(0.0f,  0.0f,  1.0f),

        vec3(-1.0f,  0.0f,  0.0f),
        vec3(-1.0f,  0.0f,  0.0f),
        vec3(-1.0f,  0.0f,  0.0f),
        vec3(-1.0f,  0.0f,  0.0f),
        vec3(-1.0f,  0.0f,  0.0f),
        vec3(-1.0f,  0.0f,  0.0f),

        vec3(1.0f,  0.0f,  0.0f),
        vec3(1.0f,  0.0f,  0.0f),
        vec3(1.0f,  0.0f,  0.0f),
        vec3(1.0f,  0.0f,  0.0f),
        vec3(1.0f,  0.0f,  0.0f),
        vec3(1.0f,  0.0f,  0.0f),

        vec3(0.0f,  -1.0f,  0.0f),
        vec3(0.0f,  -1.0f,  0.0f),
        vec3(0.0f,  -1.0f,  0.0f),
        vec3(0.0f,  -1.0f,  0.0f),
        vec3(0.0f,  -1.0f,  0.0f),
        vec3(0.0f,  -1.0f,  0.0f),

        vec3(0.0f,  1.0f,  0.0f),
        vec3(0.0f,  1.0f,  0.0f),
        vec3(0.0f,  1.0f,  0.0f),
        vec3(0.0f,  1.0f,  0.0f),
        vec3(0.0f,  1.0f,  0.0f),
        vec3(0.0f,  1.0f,  0.0f),





    };


    std::vector<GLuint> elements;
    for(int i = 0; i < vertex.size(); ++i)
        elements.push_back(i);

    for(int i = 0; i < vertex.size(); ++i)
        m_color.push_back(color);

    this->m_transform->translate(pos);

    m_transform->scale(size);

    if(haveNormals)
        setGlThings(vertex,elements,normals);
    else
        setGlThings(vertex,elements,std::vector<vec3>(),false);


}

Box::~Box()
{

}

void Box::VUpdate()
{

}

void Box::VDraw()
{
    m_p->Use();

    glBindVertexArray(vao);
    glUniform1i(4,m_haveNormals);

    m_transform->SendToShader();
    glDrawArrays(GL_TRIANGLES,0,vertices);
    //    glDrawElements(GL_TRIANGLES,m_nbr_elements,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
}

