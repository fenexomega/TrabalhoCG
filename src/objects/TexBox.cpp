#include "TexBox.h"
#include <iostream>
#include <vector>
#define VERTICES 8

#include "graphics/Texture.h"
#include "utils/Logger.h"

TexBox::TexBox(glm::vec3 size, glm::vec4 color,
         glm::vec3 pos, bool haveNormals)
{


    std::vector<vec3> vertex = {
        vec3(-0.5f, -0.5f, -0.5f),
        vec3(-0.5f,  0.5f, -0.5f),
        vec3( 0.5f,  0.5f, -0.5f),
        vec3( 0.5f,  0.5f, -0.5f),
        vec3( 0.5f, -0.5f, -0.5f),
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
        vec3( 0.5f, -0.5f,  0.5f),
        vec3( 0.5f, -0.5f, -0.5f),
        vec3( 0.5f, -0.5f, -0.5f),
        vec3( 0.5f,  0.5f, -0.5f),
        vec3( 0.5f,  0.5f,  0.5f),

        vec3(-0.5f, -0.5f, -0.5f),
        vec3( 0.5f, -0.5f, -0.5f),
        vec3( 0.5f, -0.5f,  0.5f),
        vec3( 0.5f, -0.5f,  0.5f),
        vec3(-0.5f, -0.5f,  0.5f),
        vec3(-0.5f, -0.5f, -0.5f),

        vec3(-0.5f,  0.5f, -0.5f),
        vec3(-0.5f,  0.5f,  0.5f),
        vec3( 0.5f,  0.5f,  0.5f),
        vec3( 0.5f,  0.5f,  0.5f),
        vec3( 0.5f,  0.5f, -0.5f),
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

    std::vector<vec2> texcoords =
    {
        vec2(0.0f,0.0f),
        vec2(0.0f,1.0f),
        vec2(1.0f,1.0f),
        vec2(1.0f,1.0f),
        vec2(1.0f,0.0f),
        vec2(0.0f,0.0f),

        vec2(0.0f,0.0f),
        vec2(0.0f,1.0f),
        vec2(1.0f,1.0f),
        vec2(1.0f,1.0f),
        vec2(1.0f,0.0f),
        vec2(0.0f,0.0f),

        vec2(0.0f,0.0f),
        vec2(0.0f,1.0f),
        vec2(1.0f,1.0f),
        vec2(1.0f,1.0f),
        vec2(1.0f,0.0f),
        vec2(0.0f,0.0f),

        vec2(0.0f,0.0f),
        vec2(0.0f,1.0f),
        vec2(1.0f,1.0f),
        vec2(1.0f,1.0f),
        vec2(1.0f,0.0f),
        vec2(0.0f,0.0f),

        vec2(0.0f,0.0f),
        vec2(0.0f,1.0f),
        vec2(1.0f,1.0f),
        vec2(1.0f,1.0f),
        vec2(1.0f,0.0f),
        vec2(0.0f,0.0f),

        vec2(0.0f,0.0f),
        vec2(0.0f,1.0f),
        vec2(1.0f,1.0f),
        vec2(1.0f,1.0f),
        vec2(1.0f,0.0f),
        vec2(0.0f,0.0f),
    };

    std::vector<GLuint> elements;
//    for(int i = 0; i < vertex.size(); ++i)
//        elements.push_back(i);

    for(int i = 0; i < vertex.size(); ++i)
        m_color.push_back(color);

    this->m_transform->translate(pos);

    m_transform->scale(size);

    if(haveNormals)
        setGlThings(vertex,elements,normals,true,texcoords,"box.jpg");
    else
        setGlThings(vertex,elements,std::vector<vec3>(),false);


}

TexBox::~TexBox()
{

}

void TexBox::VUpdate()
{

}

void TexBox::VDraw()
{
    m_p->Use();

    glBindVertexArray(vao);
    glUniform1i(4,m_haveNormals);
    texture->Bind();
    m_transform->SendToShader();
    glDrawArrays(GL_TRIANGLES,0,vertices);
    //    glDrawElements(GL_TRIANGLES,m_nbr_elements,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
    texture->Unbind();

}

