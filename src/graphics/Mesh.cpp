#include "Mesh.h"
#include <iostream>
#include <glm/gtc/type_ptr.hpp>
#include "Obj_Loader.h"
#include <stdexcept>

Program *Mesh::m_p;

Mesh &Mesh::operator=(Mesh &v)
{
    vao = v.vao;
    for(int i = 0;i < VB_BUFFERS;++i)
        vbo[i] = v.vbo[i];
    return *this;
}

Mesh::Mesh(const Mesh& mesh)
{
    vao = mesh.vao;
    for(int i = 0;i < VB_BUFFERS;++i)
        vbo[i] = mesh.vbo[i];
}

Mesh::Mesh()
{

}

void Mesh::setGlThings(std::vector<float> vertex,
                       std::vector<GLuint> elements)
{
    if(m_p == NULL)
    {
        m_p = new Program;
        m_p->AttachShader(new Shader("gamev.glsl",Shader::VERTEX_SHADER));
        m_p->AttachShader(new Shader("gamef.glsl",Shader::FRAGMENT_SHADER));
        m_p->BindFragDataLocation("finalColor",0);

        m_p->Link();

        m_p->Use();
        m_p->PrintActiveVertexInput();
        m_p->PrintActiveUniforms();
    }
    model = glm::mat4(1);
    vertices = vertex.size();
    m_elements = elements.size();

    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glGenBuffers(VB_BUFFERS,vbo);
    glBindBuffer(GL_ARRAY_BUFFER,vbo[VB_VERTEX]);
    glBufferData(GL_ARRAY_BUFFER,vertices*sizeof(float),vertex.data(),GL_STATIC_DRAW);
    
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),0);

    glBindBuffer(GL_ARRAY_BUFFER,vbo[VB_COLORS]);
    glBufferData(GL_ARRAY_BUFFER,vertices*sizeof(float),m_color.data(),GL_STATIC_DRAW);

    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,3*sizeof(float),0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vbo[VB_ELEMENTS]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,m_elements*sizeof(GLuint),elements.data(),GL_STATIC_DRAW);

    glBindVertexArray(0);
}
Transform &Mesh::transform()
{
    return m_transform;
}

void Mesh::setTransform(const Transform &trans)
{
    m_transform = trans;
}


Mesh::Mesh(std::vector<float> vertex,std::vector<float> colors,
           std::vector<GLuint> elements)
{
    for(uint i = 0; i < colors.size(); i += 3)
        m_color.push_back(glm::vec3(colors[i],colors[i+1],colors[i+2]));
    setGlThings(vertex,elements);
}

Mesh::Mesh(std::vector<float> vertex, glm::vec3 color,
           std::vector<GLuint> elements)
{
    for(int i = 0; i < vertices; ++i)
        m_color.push_back(color);

    setGlThings(vertex,elements);
}

Mesh::Mesh(std::string modelFile, glm::vec3 color)
{
    if(modelFile.empty())
        throw std::runtime_error("Null string of model name Model.cpp:102");
    IndexedModel model = OBJModel(modelFile).ToIndexedModel();



    std::vector<GLfloat> vertex;

    for(glm::vec3 f :model.positions )
    {
        vertex.push_back(f.x);
        vertex.push_back(f.y);
        vertex.push_back(f.z);

    }

    vertices = model.positions.size();

    for(int i = 0; i < vertices; ++i)
        m_color.push_back(color);

    auto elements = model.indices;
    setGlThings(vertex,elements);

}

void Mesh::changeColor(glm::vec3 color, bool original )
{
    std::vector<glm::vec3> t_colors;

    if(original)
    {
        t_colors = m_color;
    }
    else
    {
        for(auto i = 0; i < vertices; ++i)
            t_colors.push_back(color);

    }
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER,vbo[VB_COLORS]);
    glBufferData(GL_ARRAY_BUFFER,vertices*sizeof(float),t_colors.data(),GL_STATIC_DRAW);
    glBindVertexArray(0);
}

void Mesh::VUpdate()
{

}

void Mesh::VDraw()
{
    m_p->Use();
    glBindVertexArray(vao);
    m_transform.SendToShader();
    glDrawElements(GL_TRIANGLES,m_elements,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    glDeleteBuffers(VB_BUFFERS,vbo);
    glDeleteVertexArrays(1,&vao);
}
