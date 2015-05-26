#include "Game.h"

#include "graphics/Mesh.h"

#include "utils/Logger.h"
#include "graphics/Program.h"
#include "graphics/Camera.h"
#include "objects/Grid.h"
#include "input/sysInput.h"
#include "objects/Arrow.h"
#include "objects/CoordinateArrows.h"
#include "objects/Box.h"
#include "objects/Square.h"
#include "objects/Quarto.h"
#include <graphics/Shadow.h>

#include <graphics/Light.h>
#include "game/GameInput.h"
#define TAM_LADRILHO 0.32f
#define ALTURA 2.0f
#define LASTOF(VEC) (VEC[VEC.size()-1])


std::ostream& operator<<(std::ostream& os, glm::vec2 vec)
{

    return os << "(" << vec.x << "," << vec.y  <<  ")";
}


Game::Game()
{

}

Game::~Game()
{

}



void Game::init()
{
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);




    etc.push_back(new CoordinateArrows(vec3(0,0,0)));

//    meshes.push_back(new Box(vec3(1.0,1.0,1.0),vec3(0,0.5,0.5)));
//    meshes.push_back(new Square(glm::vec2(1.0,1.0),vec3(0.5,0.5,0),vec3(0,0,-2)));
//    meshes.push_back(new Quarto);

    etc.push_back(new Grid(vec3(0,0,0),vec2(TAM_LADRILHO,TAM_LADRILHO),27,
                                    vec3(1.f,1.f,1.f)));

    cam = new Camera(vec3(0,0.5,3.0f),vec3(0,0.5,0),vec3(0,1,0),70.0f);

    Light luz {glm::vec4(0,-1,0,0)};

    //COLOCAR OBJETOS
    meshes.push_back(new Mesh("Rack.obj",vec3(0.2,0.3,0.6)));
    LASTOF(meshes)->transform()->translate(1.2,0.64f,2.7);
    LASTOF(meshes)->transform()->rotate(90,0,1,0);


    sombras.push_back(new Shadow
             (LASTOF(meshes),
              vec3(0,0,0),luz));

    meshes.push_back(new Mesh("Gaming Desk.obj",vec3(0.5f,0.0f,0.3f)));
    LASTOF(meshes)->transform()->translate(1.2,-0.025f,2);
    LASTOF(meshes)->transform()->rotate(-90,0,1,0);
    LASTOF(meshes)->transform()->scale(0.25f,0.25f,0.25f);


    sombras.push_back(new Shadow
             (LASTOF(meshes),
              vec3(0,0,0),luz));

    meshes.push_back(new Mesh("Bed.obj",vec3(1.0f,0.f,0.3f)));
    LASTOF(meshes)->transform()->translate(-0.8f,0.3,3.3f);
    LASTOF(meshes)->transform()->rotate(-180,0,1,0);
    LASTOF(meshes)->transform()->scale(0.4f,0.4f,0.4f);

    sombras.push_back(new Shadow
             (LASTOF(meshes),
              vec3(0,0,0),luz));

    meshes.push_back(new Mesh("soccer ball.obj",vec3(0.8f,0.8f,1.0f)));
    LASTOF(meshes)->transform()->translate(-0,0.05f,1.2f);
    LASTOF(meshes)->transform()->scale(0.001f,0.001f,0.001f);



    sombras.push_back(new Shadow
             (LASTOF(meshes),
              vec3(0,0,0),luz));
}

void Game::update(double delta)
{
    cam->Update();

    auto mouseWheel = sysInput::getMouseWheel();
    static GameInput gi(meshes);
//    LOG(mouseWheel);
    gi.Update();

    if(sysInput::isKeyPressed(SDL_SCANCODE_W))
        cam->Move(0,0,-0.02f);
    if(sysInput::isKeyPressed(SDL_SCANCODE_S))
        cam->Move(0,0,0.02f);
    if(sysInput::isKeyPressed(SDL_SCANCODE_A))
        cam->Move(-0.02f,0,0);
    if(sysInput::isKeyPressed(SDL_SCANCODE_D))
        cam->Move(0.02f,0,0);

    if(sysInput::isKeyPressed(SDL_SCANCODE_LEFT))
        cam->RotateY(-0.02f);
    if(sysInput::isKeyPressed(SDL_SCANCODE_RIGHT))
        cam->RotateY(0.02f);
    if(sysInput::isKeyPressed(SDL_SCANCODE_UP))
        cam->RotateX(-0.01f);
    if(sysInput::isKeyPressed(SDL_SCANCODE_DOWN))
        cam->RotateX(0.01f);

    if(sysInput::isKeyDown(SDL_SCANCODE_F6))
        cam->changePerspective();

    if((sysInput::isKeyPressed(SDL_SCANCODE_MINUS)))
        cam->setFOV(cam->FOV() + 0.5f);
    if(sysInput::isKeyPressed(SDL_SCANCODE_EQUALS))
        cam->setFOV(cam->FOV() - 0.5f);


    if(sysInput::isKeyDown(SDL_SCANCODE_F5))
    {
        static bool b = true;
        meshes.at(0)->changeColor(glm::vec3(1.0,1.0,1.0),b = !b);

    }

    meshes[3]->transform()->rotate(-1.5f,1,0,1.0);
//    meshes[3]->transform()->translate(0,,0.0f);


    for(auto m : meshes)
        m->VUpdate();
    for(auto m : etc)
        m->VUpdate();
    for(auto m : sombras)
        m->VUpdate();
}

void Game::pause()
{
}

void Game::draw(double delta)
{
    glClearColor(0.3f,0.3f,0.3f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for(auto m : etc)
        m->VDraw();
    for(auto m : sombras)
        m->VDraw();
    for(auto m : meshes)
        m->VDraw();
}

void Game::dispose()
{
    for(auto m : meshes)
       delete m;
}
