#include "Mesh.h"
#include <iostream>
#include <glm/gtc/type_ptr.hpp>
#include "Obj_Loader.h"
#include <stdexcept>
#include "utils/Logger.h"

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
    m_transform = new Transform;
}

void Mesh::setGlThings(std::vector<vec3> vertex,
                       std::vector<GLuint> elements, std::vector<vec3> normals,
                       bool haveNormals)
{
    m_haveNormals = haveNormals;
    if(normals.empty())
    {
        LOG("Tamanho Vertex = " << vertex.size());
        vec3 aux,v1,v2,v3;
        for(uint i = 0; i < elements.size(); i += 3)
        {
            v1 = vertex[elements[i]];
            v2 = vertex[elements[i+1]];
            v3 = vertex[elements[i+2]];

            aux = glm::cross((v2 - v1),(v3 - v1));
            aux = glm::normalize(aux);
            LOG(aux.x << " | " << aux.y << " | " << aux.z);
            normals.push_back(aux);
            normals.push_back(aux);
            normals.push_back(aux);
        }
    }
    m_normals = normals;
    m_vertex = vertex;

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
    vertices = vertex.size()*3;
    m_nbr_elements = elements.size();
    m_elements = elements;

    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);


    glGenBuffers(VB_BUFFERS,vbo);
    glBindBuffer(GL_ARRAY_BUFFER,vbo[VB_VERTEX]);
    glBufferData(GL_ARRAY_BUFFER,vertices*sizeof(float),
                 vertex.data(),GL_STATIC_DRAW);
    
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),0);
    glEnableVertexAttribArray(0);


    glBindBuffer(GL_ARRAY_BUFFER,vbo[VB_COLORS]);
    glBufferData(GL_ARRAY_BUFFER,vertices*sizeof(float),
                 m_color.data(),GL_DYNAMIC_DRAW);

    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,3*sizeof(float),0);
    glEnableVertexAttribArray(1);


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vbo[VB_ELEMENTS]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,m_nbr_elements*sizeof(GLuint),
                 elements.data(),GL_STATIC_DRAW);


    //FIXME problemas nas normais
    glBindBuffer(GL_ARRAY_BUFFER,vbo[VB_NORMALS]);
    glBufferData(GL_ARRAY_BUFFER,normals.size()*3*sizeof(float),
                 normals.data(),GL_STATIC_DRAW);
    glVertexAttribPointer(2,3,GL_FLOAT,GL_FALSE,3*sizeof(float),0);

    glEnableVertexAttribArray(2);


    // THIS NEVER WORKED
    //    glBindBuffer(GL_ARRAY_BUFFER,vbo[VB_BOOL_NORMALS]);
    //    glBufferData(GL_ARRAY_BUFFER,sizeof(GLint),&aux,GL_STATIC_DRAW);
    ////    glVertexAttribPointer(3,1,GL_INT,GL_FALSE,sizeof(GLint),0);
    //        glVertexAttribIPointer(3,1,GL_INT,0,&aux);

    //    glEnableVertexAttribArray(3);
    glBindVertexArray(0);
}
std::vector<glm::vec3> Mesh::normals() const
{
    return m_normals;
}

void Mesh::setNormals(const std::vector<glm::vec3> &normals)
{
    m_normals = normals;
}

std::vector<GLuint> Mesh::elements() const
{
    return m_elements;
}

void Mesh::setElements(const std::vector<GLuint> &elements)
{
    m_elements = elements;
}

std::vector<glm::vec3> Mesh::vertex() const
{
    return m_vertex;
}

void Mesh::setVertex(const std::vector<glm::vec3> &vertex)
{
    m_vertex = vertex;
}

Transform *Mesh::transform() const
{
    return m_transform;
}

void Mesh::setTransform(Transform *trans)
{
    m_transform = trans;
}


Mesh::Mesh(std::vector<vec3> vertex, std::vector<GLfloat> colors,
           std::vector<GLuint> elements)
{
    m_transform = new Transform;

    for(uint i = 0; i < colors.size(); i += 3)
        m_color.push_back(glm::vec3(colors[i],colors[i+1],colors[i+2]));
    setGlThings(vertex,elements);
}

Mesh::Mesh(std::vector<vec3> vertex, glm::vec3 color,
           std::vector<GLuint> elements)
{
    m_transform = new Transform;

    for(int i = 0; i < vertex.size(); ++i)
        m_color.push_back(color);

    setGlThings(vertex,elements);
}

Mesh::Mesh(std::string modelFile, glm::vec3 color)
{
    m_transform = new Transform;

    if(modelFile.empty())
        throw std::runtime_error("Null string of model name Model.cpp:102");
    IndexedModel model = OBJModel(modelFile).ToIndexedModel();



    std::vector<vec3> vertex = model.positions;

    //    for(glm::vec3 f :model.positions )
    //    {
    //        vertex.push_back(vec3(f.x,f.y,f.z));

    //    }

    vertices = model.positions.size();

    for(int i = 0; i < vertices; ++i)
        m_color.push_back(color);

    auto elements = model.indices;
    setGlThings(vertex,elements,model.normals);

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
    glBufferData(GL_ARRAY_BUFFER,vertices*sizeof(float),t_colors.data(),GL_DYNAMIC_DRAW);
    glBindVertexArray(0);
}

void Mesh::VUpdate()
{

}

void Mesh::VDraw()
{
    m_p->Use();

    glBindVertexArray(vao);
    glUniform1i(4,m_haveNormals);

    m_transform->SendToShader();
    glDrawElements(GL_TRIANGLES,m_nbr_elements,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    //    delete m_transform;
    glDeleteBuffers(VB_BUFFERS,vbo);
    glDeleteVertexArrays(1,&vao);
}
