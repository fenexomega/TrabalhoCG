#include "FrameBuffer.h"
#include "Texture.h"
#include "Window.h"
#include "utils/Logger.h"

#include <input/sysInput.h>

FrameBuffer::FrameBuffer(int w,int h)
{
    glGenFramebuffers(1,&m_fbo);
    glBindFramebuffer(GL_FRAMEBUFFER,m_fbo);
    tx = new Texture(w,h);
    glFramebufferTexture2D(GL_FRAMEBUFFER,GL_COLOR_ATTACHMENT0,GL_TEXTURE_2D,tx->getTextureId(),0);
    glBindFramebuffer(GL_FRAMEBUFFER,0);
}

void FrameBuffer::Bind()
{
    glBindFramebuffer(GL_FRAMEBUFFER,m_fbo);

}

void FrameBuffer::Unbind()
{
    glBindFramebuffer(GL_FRAMEBUFFER,0);

}

glm::vec3 FrameBuffer::ReadMousePixel()
{
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
    {
        LOG("Framebuffer não Pronto");
        return glm::vec3();
    }
    static Window win;

    GLfloat data[3];
    auto v = sysInput::getMousePos();
    glReadPixels(v.x,win.getHeight() - v.y,1,1,GL_RGB,GL_FLOAT,(void *)&data[0]);
    return glm::vec3(data[0],data[1],data[2]);
}



FrameBuffer::~FrameBuffer()
{
    delete tx;
    glDeleteFramebuffers(1,&m_fbo);
}

