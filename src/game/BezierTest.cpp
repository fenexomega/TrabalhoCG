#include "BezierTest.h"

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
#include "graphics/Bezier.h"
#include "graphics/Spline.h"
#include <graphics/Light.h>
#include <graphics/Sphere.h>
#include "game/GameInput.h"
#define TAM_LADRILHO 0.32f
#define ALTURA 2.0f
#define LASTOF(VEC) (VEC[VEC.size()-1])



BezierTest::BezierTest()
{

}

BezierTest::~BezierTest()
{

}



void BezierTest::init()
{
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);

    vec3 control_points[] = {
        {0.0f ,0.0f,0.0f},
        {0.25f,1.0f,0.0f},
        {0.50f,1.0f,0.0f},
        {0.75f,0.0f,0.0f},
    };


    vec3 control_points1[] = {
        {0.0f,0.0f,0.0f},
        {0.0f,0.0f,0.0f},
        {1.0f,1.0f,0.0f},
        {2.0f,2.0f,0.0f},
        {3.0f,1.5f,0.0f},
        {4.0f,3.0f,0.0f},
        {5.0f,1.0f,0.0f},
        {5.0f,1.0f,6.0f},
        {6.0f,-2.0f,3.0f},
        {10.0f,1.0f,6.0f},
        {13.0f,1.0f,8.0f},
        {13.0f,1.0f,8.0f},






    };

    int numPoints = sizeof(control_points1)/sizeof(float)/3;

    etc.push_back(new Bezier(control_points,80));
    etc.push_back(new Spline(control_points1,numPoints,30));

//    etc.push_back(new Grid(vec3(0,0,0),vec2(TAM_LADRILHO,TAM_LADRILHO),27,
//                                    vec3(1.f,1.f,1.f)));

    cam = new Camera(vec3(0,0.5,3.0f),vec3(0,0.5,0),vec3(0,1,0),70.0f);

    Light luz {glm::vec3(0,-1,0)};


}

void BezierTest::update(double delta)
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


    for(auto m : meshes)
        m->VUpdate();
    for(auto m : etc)
        m->VUpdate();
    for(auto m : sombras)
        m->VUpdate();
}

void BezierTest::pause()
{
}

void BezierTest::draw(double delta)
{
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for(auto m : etc)
        m->VDraw();
    for(auto m : sombras)
        m->VDraw();
    for(auto m : meshes)
        m->VDraw();
}

void BezierTest::dispose()
{
    for(auto m : meshes)
       delete m;
}
