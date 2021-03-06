#include "Window.h"

#include "utils/Logger.h"
#include <SDL2/SDL_image.h>
#include <ctime>

SDL_Window *Window::SDLwindow;
SDL_GLContext Window::GLcontext;
int Window::width;
int Window::height;
std::string Window::_title;



int Window::getWidth()
{
    return width;
}

void Window::setWidth(int value)
{
    width = value;
}

int Window::getHeight()
{
    return height;
}

void Window::setHeight(int value)
{
    height = value;
}

std::string Window::getTitle()
{
    return _title;
}

void Window::setTitle(const std::string &value)
{
    _title = value;
}

void Window::InvertImage(GLuint*& data)
{
    GLuint *temp = new GLuint[width*height];
    int OriginalImageHeight;

    for(int y = 0; y < height ; ++y)
    {
        OriginalImageHeight = height - y -1;
        for(int x = 0; x < width ; ++x)
        {

            temp[x + width*y] = data[x + width*OriginalImageHeight];
        }
    }
    delete data;
    data = temp;
}
void Window::CreateGlContext()
{




}

Window::Window()
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,GL_MAJOR);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,GL_MINOR);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,SDL_TRUE);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE,8);
    // MULTISAMPLING ANTI ALIAS X4
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,4);
//    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,2);

}

Window::~Window()
{

}

void Window::SwapBuffers()
{
    SDL_GL_SwapWindow(SDLwindow);
}

bool Window::UserWannaQuit()
{
    SDL_Event e;
    SDL_PollEvent(&e);
    return e.type == SDL_QUIT;
}

void Window::CreateWindow(int _width, int _height, std::string title, bool isFullscreen )
{
    static int windowsFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
    if(SDLwindow)
        SDL_DestroyWindow(SDLwindow);

    if(GLcontext)
        SDL_GL_DeleteContext(GLcontext);

    if(isFullscreen)
        windowsFlags |=  SDL_WINDOW_FULLSCREEN;
    _title = title;
    this->width = _width;
    this->height = _height;
    SDLwindow = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED
                                 ,SDL_WINDOWPOS_CENTERED,width,height,
                                 windowsFlags);

    GLcontext = SDL_GL_CreateContext(SDLwindow);

    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK)
    {
       LOG("Couldn't Initialize Glew. Exiting");
       EXIT();
    }

    glViewport(0,0,width,height);
}

void Window::Destroy()
{
    SDL_GL_DeleteContext(GLcontext);
    SDL_DestroyWindow(SDLwindow);
}

void Window::TakeShot()
{
    time_t t = time(0);
    std::string strtime(std::ctime(&t));
    LOG(strtime);
    LOG("WIDTH = " << width);
    GLuint *data = new GLuint[width*height];
    glReadPixels(0,0,width,height,GL_RGBA,GL_UNSIGNED_BYTE,(void *)&data[0]);
    InvertImage(data);
    SDL_Surface *sshot = SDL_CreateRGBSurfaceFrom(data,width,height,8*4,width*4,0x000000FF,0x0000FF00,0x00FF0000,0xFF000000 );

    //Gambiarra para remover o último caractere do strtime, que é um \n
    const char * printName = (strtime.erase(strtime.npos + strtime.size() ) + ".png").c_str();

    IMG_SavePNG(sshot, printName);
    SDL_FreeSurface(sshot);
    delete data;
    PRINT("Screenshot Taken!");
}

void Window::SetTitle(std::string title)
{
    SDL_SetWindowTitle(SDLwindow,title.c_str());
}


