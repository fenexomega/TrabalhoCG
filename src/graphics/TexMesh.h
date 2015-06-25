/*
 * =====================================================================================
 *
 *       Filename:  mesh.hpp
 *
 *    Description:  <F4><F4>:w
 *
 *
 *        Version:  1.0
 *        Created:  14-01-2015 22:54:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (fgm), mehner.fritz@fh-swf.de
 *   Organization:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */
#ifndef TEXMESH
#define TEXMESH

#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <vector>
#include "graphics/Transform.h"
#include "graphics/Program.h"
#include "Mesh.h"
#include <memory>

class Program;
class Texture;
using glm::vec2;
using glm::vec3;

class TexMesh : public Mesh
{
protected:
    TexMesh();
    void setGlThings(std::vector<vec3> vertex,
                     std::vector<GLuint> elements,
                     std::vector<glm::vec3> normals = std::vector<vec3>(),
                     bool haveNormals = true,
                     std::vector<glm::vec2> texCoords = std::vector<vec2>(),
                     std::string texFile = "");
//    static Program *m_p;
    GLuint vao;
    Texture *texture;
    int vertices;
    int m_nbr_elements;
    std::vector<glm::vec4> m_color;
    std::vector<glm::vec3> m_vertex;
    std::vector<glm::vec3> m_normals;
    std::vector<GLuint> m_elements;
    glm::mat4 model{};
    Transform* m_transform{};
    GLint m_haveNormals;
private:
	enum {
		VB_VERTEX,
		VB_COLORS,
        VB_ELEMENTS,
        VB_TEXTURE_COORDS,
        VB_NORMALS,
        VB_BUFFERS
	};
	GLuint vbo[VB_BUFFERS];
public:
    TexMesh& operator=(TexMesh& v);
    TexMesh(const TexMesh &mesh);

    TexMesh(std::vector<vec3> vertex, std::vector<GLfloat> colors,
         std::vector<GLuint> elements);
    TexMesh(std::vector<vec3> vertex, glm::vec4 colors,
         std::vector<GLuint> elements);
    TexMesh(std::string modelFile, glm::vec4 color);

    virtual void VUpdate();
    virtual void VDraw();

    void changeColor(glm::vec4 color, bool original= false );
    virtual ~TexMesh();

    Transform *transform() const;
    void setTransform(Transform *trans);
    std::vector<glm::vec3> vertex() const;
    void setVertex(const std::vector<glm::vec3> &vertex);
    std::vector<GLuint> elements() const;
    void setElements(const std::vector<GLuint> &elements);
    std::vector<glm::vec3> normals() const;
    void setNormals(const std::vector<glm::vec3> &normals);
    TexMesh(std::string filename, std::string texturefile, glm::vec4 color);
};
#endif
