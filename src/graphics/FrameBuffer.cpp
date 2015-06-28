#include "FrameBuffer.h"
#include "Texture.h"
#include "Window.h"
#include "utils/Logger.h"

#include <input/sysInput.h>

FrameBuffer::FrameBuffer(int w,int h)
{
    static Window win;

    glGenFramebuffers(1,&m_fbo);
    glBindFramebuffer(GL_FRAMEBUFFER,m_fbo);
    tx = new Texture(w,h);
    glFramebufferTexture2D(GL_FRAMEBUFFER,GL_COLOR_ATTACHMENT0,GL_TEXTURE_2D,tx->getTextureId(),0);

    //Criar RenderBuffer para não perder stencil nem depth
    glGenRenderbuffers(1, &m_rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, m_rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, win.getWidth(), win.getHeight());

    glBindRenderbuffer(GL_RENDERBUFFER, 0);

    glBindFramebuffer(GL_FRAMEBUFFER,0);

}

void FrameBuffer::Bind()
{
    glBindFramebuffer(GL_FRAMEBUFFER,m_fbo);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_rbo);

    glBindRenderbuffer(GL_RENDERBUFFER, m_rbo);


}

void FrameBuffer::Unbind()
{
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
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

    GLfloat data[4];
    auto v = sysInput::getMousePos();
    glReadPixels(v.x,win.getHeight() - v.y,1,1,GL_RGBA,GL_FLOAT,(void *)&data[0]);
    return glm::vec3(data[0],data[1],data[2]);
}



FrameBuffer::~FrameBuffer()
{

    delete tx;
    glDeleteRenderbuffers(1,&m_rbo);
    glDeleteFramebuffers(1,&m_fbo);
}

