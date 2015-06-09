#include "Sphere.h"

#define PI 3.1416f
#define TORAD(X) X*PI/180.0f

#include <vector>

using std::vector;

Sphere::Sphere(float r, GLint slices, GLint stacks)
{
    float u = 0;
    float v = -PI/2.0f;
    vec3 point;
    vector<vec3> vertex;
    vector<GLuint> elements;
    int e = 0;
    while(u < 3.0f/2*PI && v < PI/2.0f)
    {
        point.x = r*cos(v)*cos(u);
        point.y = r*cos(v)*sin(u);
        point.z = r*sin(v);

        vertex.push_back(point);
        elements.push_back(e++);
        m_color.push_back(vec3(0,1,0));

        u += 1.0f/slices;
        v += 1.0f/stacks;

    }
    setGlThings(vertex,elements,std::vector<vec3>(),false);

}


void Sphere::VDraw()
{
    m_p->Use();

    glBindVertexArray(vao);
    glUniform1i(4,m_haveNormals);

    m_transform->SendToShader();
    glDrawElements(GL_TRIANGLES,m_nbr_elements,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
}
