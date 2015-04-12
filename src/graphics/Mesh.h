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
#ifndef MESH
#define MESH

#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <vector>
#include "graphics/Transform.h"
#include "graphics/Program.h"

class Program;

class Mesh
{
protected:
    Mesh();
    void setGlThings(std::vector<float> vertex,
                     std::vector<GLuint> elements);
    static Program *m_p;
    GLuint vao;
    int vertices;
    int m_elements;
    std::vector<glm::vec3> m_color;
    glm::mat4 model{};
    Transform m_transform;



private:

	

	enum {
		VB_VERTEX,
		VB_COLORS,
        VB_ELEMENTS,

		VB_BUFFERS
	};
	GLuint vbo[VB_BUFFERS];
public:
    Mesh& operator=(Mesh& v);
    Mesh(const Mesh &mesh);

    Mesh(std::vector<float> vertex, std::vector<float> colors, std::vector<GLuint> elements);
    Mesh(std::vector<float> vertex, glm::vec3 colors, std::vector<GLuint> elements);

    virtual void VUpdate();
    virtual void VDraw();

    void changeColor(glm::vec3 color, bool original= false );
    virtual ~Mesh();

    Transform& transform();
    void setTransform(const Transform &trans);
};
#endif
