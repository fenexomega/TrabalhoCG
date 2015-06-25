#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <GL/glew.h>
#include <glm/vec3.hpp>

class Texture;
class FrameBuffer
{
private:
    GLuint m_fbo;
    Texture *tx;
public:
    FrameBuffer(int w, int h);
    void Bind();
    void Unbind();
    glm::vec3 ReadMousePixel();
    ~FrameBuffer();
};

#endif // FRAMEBUFFER_H
