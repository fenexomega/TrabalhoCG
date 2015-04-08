#ifndef ENGINE_H
#define ENGINE_H

#include "graphics/SysGraphics.h"
#include "interfaces/iGame.h"

#include <iostream>


class Engine
{

private:
public:
    Engine();
    ~Engine();

    static void DisposeSystems();
    static void InitSystems();
    static void Run(iGame *game);
    static void CreateWindow(int width,int height,std::string title);
    static void Buttons();
};
#endif // ENGINE_H
