#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>
#define GL_MAJOR 3
#define GL_MINOR 3



class Window
{
private:
    static SDL_Window *SDLwindow;
    static SDL_GLContext GLcontext;
    static int width, height;
    void CreateGlContext();
public:
    Window();
    ~Window();
    void SwapBuffers();
    bool UserWannaQuit();
    void CreateWindow(int width = 800, int height = 600, std::string title = "CG FrameWork", bool isFullscreen = false);
    void Destroy();
    void SetTitle(std::string title);
    static int getWidth();
    static void setWidth(int value);
    static int getHeight();
    static void setHeight(int value);
};

#endif // WINDOW_H
