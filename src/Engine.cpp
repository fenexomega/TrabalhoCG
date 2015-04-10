#include "Engine.h"

#include "input/sysInput.h"

#include "graphics/Window.h"
#include "utils/Timer.h"
#include "utils/Logger.h"
#include "graphics/Mesh.h"



Engine::Engine()
{
    InitSystems();
}

void Engine::InitSystems()
{
    Logger::CreateLogFile();
    LOG("Initializing Systems");
    SysGraphics::init();

    Window win;
    win.CreateWindow(800,600,"0xframework");
    SysGraphics::getGlInfo();

    //Automaticamente chmará esse função
    //na Saída.
    atexit(DisposeSystems);
}

void Engine::DisposeSystems()
{
    LOG("Disposing Systems");
    SysGraphics::dispose();
    LOG("Done.");
    Logger::CloseLogFile();
    exit(0);
}



void Engine::Run(iGame *game)
{
    Window win;
	game->init();
    Timer time;
    double timeFrame,totalTime = 0;
    int framerate = 0;

    while(!sysInput::UserWannaQuit())
    {
        timeFrame = time.getTime();
        totalTime += timeFrame;
        framerate++;

        if(totalTime >= 1.0)
        {
            win.SetTitle("0xFramework " + TOSTR(framerate) + " FPS");
            framerate = totalTime = 0;
        }

        sysInput::update();
        game->update(timeFrame);

        Buttons();
        SDL_Delay(1000.0f/60);

        game->draw(timeFrame);

        win.SwapBuffers();
    }
	game->dispose();

    win.Destroy();
}

void Engine::Buttons()
{
#ifndef RELEASE
//    if(sysInput::isKeyDown(SDL_SCANCODE_F4))
//        Mesh::PolygonMode = GL_TRIANGLES;
//    if(sysInput::isKeyDown(SDL_SCANCODE_F5))
//        Mesh::PolygonMode = GL_LINES;
//    if(sysInput::isKeyDown(SDL_SCANCODE_F6))
//        Mesh::PolygonMode = GL_POINTS;
#endif
}

Engine::~Engine()
{

}

