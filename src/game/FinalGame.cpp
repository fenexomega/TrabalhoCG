#include "FinalGame.h"

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
#include <graphics/Light.h>
#include <graphics/Window.h>
#include "game/GameInput.h"
#include <objects/TexBox.h>
#define TAM_LADRILHO 0.32f
#define ALTURA 2.0f
#define LASTOF(VEC) (VEC[VEC.size()-1])




FinalGame::FinalGame()
{

}

FinalGame::~FinalGame()
{

}



void FinalGame::init()
{

    Window win;
    win.CreateWindow(1024,728,"Trabalho Final");
	glEnable(GL_DEPTH_TEST);
//    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    float altura = 2.0f;



//    etc.push_back(new Bezier(control_points,500));
//    etc.push_back(new CoordinateArrows(vec3(0,0,0)));

//    meshes.push_back(new Box(vec3(1.0,1.0,1.0),vec3(0,0.5,0.5)));r
//    meshes.push_back(new Square(glm::vec2(1.0,1.0),vec3(0.5,0.5,0),vec3(0,0,-2)));
//    meshes.push_back(new Quarto);

//    etc.push_back(new Grid(vec3(0,0,0),vec2(TAM_LADRILHO,TAM_LADRILHO),27,
//                                    vec3(1.f,1.f,1.f)));


//    PAREDES
    meshes.push_back(new Box(vec3(10.0f,altura,0.01f),vec4(0.0f,0.3f,1,1),vec3(0,altura/2,5)));
    meshes.push_back(new Box(vec3(10.0f,altura,0.01f),vec4(0.0f,0.3f,1,1),vec3(0,altura/2,-5)));

    meshes.push_back(new Box(vec3(0.01f,altura,10.0f),vec4(0.0f,0.3f,1,1),vec3(5,altura/2,0)));
    meshes.push_back(new Box(vec3(0.01f,altura,10.0f),vec4(0.0f,0.3f,1,1),vec3(-5,altura/2,0)));

    meshes.push_back(new Box(vec3(10.0f,0.01f,10.0f),vec4(0.0f,0.3f,1,1),vec3(0,altura,0)));
    meshes.push_back(new Box(vec3(10.0f,0.01f,10.0f),vec4(1.0f,1.f,1.0f,1.0f)));

    //COLOCAR OBJETOS

    meshes.push_back(new Box(vec3(1.0f,1.0f,1.0f),vec4(1.0f,0,0,1),vec3(-1,0.5f,-2.0f)));
    meshes.push_back(new Box(vec3(1.0f,1.0f,1.0f),vec4(0.0f,0.3f,0,1),vec3(-2,0.5,1.0)));
    texturizados.push_back(new TexBox(vec3(1.0f,1.0f,1.0f),vec4(0.0f,0.3f,0,1),vec3(2,0.5,1.0)));



    etc.push_back(new Light(glm::vec3(0,altura ,0.0f),vec3(2.0f,0.5f,1.0f)));

    transparentes.push_back(new Box(vec3(1.0),vec4(1.0,1.0,0.0,0.5f),vec3(-1,0.5f,0)));
    transparentes.push_back(new Box(vec3(1.0),vec4(1.0,0.0,0.0,0.5f),vec3(-1,0.5f,1)));


    // A CAMERA TEM DE IR POR ÚLTIMO, POIS ELA USA O SHADER JÁ SETADO
    cam = new Camera(vec3(0,0.5,3.0f),vec3(0,0.5,0),vec3(0,1,0),70.0f);
    selectedCam = cam;

    multicams[0] = new Camera(vec3(0,0.5,3.0f),vec3(0,0.5,0),vec3(0,1,0),70.0f);
    multicams[1] = new Camera(vec3(0,0.5,3.0f),vec3(0,0.5,0),vec3(0,1,0),70.0f);
    multicams[2] = new Camera(vec3(0,0.5,3.0f),vec3(0,0.5,0),vec3(0,1,0),70.0f);
    multicams[3] = new Camera(vec3(0,0.5,3.0f),vec3(0,0.5,0),vec3(0,1,0),70.0f);

    camNum = 0;
}


void FinalGame::update(double delta)
{

    selectedCam->Update();

    if(sysInput::isKeyPressed(SDL_SCANCODE_W))
        selectedCam->Move(0,0,-0.02f);
    if(sysInput::isKeyPressed(SDL_SCANCODE_S))
        selectedCam->Move(0,0,0.02f);
    if(sysInput::isKeyPressed(SDL_SCANCODE_A))
        selectedCam->Move(-0.02f,0,0);
    if(sysInput::isKeyPressed(SDL_SCANCODE_D))
        selectedCam->Move(0.02f,0,0);
    if(sysInput::isKeyPressed(SDL_SCANCODE_LCTRL))
        selectedCam->Move(0,-0.02f,0);
    if(sysInput::isKeyPressed(SDL_SCANCODE_SPACE))
        selectedCam->Move(0,0.02f,0);

    if(sysInput::isKeyPressed(SDL_SCANCODE_LEFT))
        selectedCam->RotateY(-0.02f);
    if(sysInput::isKeyPressed(SDL_SCANCODE_RIGHT))
        selectedCam->RotateY(0.02f);
    if(sysInput::isKeyPressed(SDL_SCANCODE_UP))
        selectedCam->RotateX(-0.01f);
    if(sysInput::isKeyPressed(SDL_SCANCODE_DOWN))
        selectedCam->RotateX(0.01f);

    if(sysInput::isKeyDown(SDL_SCANCODE_F6))
        selectedCam->changePerspective();

    if(sysInput::isKeyDown(SDL_SCANCODE_F5))
    {
        camNum = 0;
        selectedCam = multicams[camNum];
        multiView = !multiView;
    }
    if(sysInput::isKeyDown(SDL_SCANCODE_TAB))
        if(multiView)
        {
            camNum = (++camNum)%maxCams;
            selectedCam = multicams[camNum];
        }

    if((sysInput::isKeyPressed(SDL_SCANCODE_MINUS)))
        selectedCam->setFOV(selectedCam->FOV() + 0.5f);
    if(sysInput::isKeyPressed(SDL_SCANCODE_EQUALS))
        selectedCam->setFOV(selectedCam->FOV() - 0.5f);


    for(auto m : meshes)
        m->VUpdate();
    for(auto m : texturizados)
        m->VUpdate();
    for(auto m : etc)
        m->VUpdate();
    for(auto m : transparentes)
        m->VUpdate();
}

void FinalGame::pause()
{

}

void FinalGame::draw(double delta)
{
    static Window win;

    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(!multiView)
    {
        glViewport(0,0,win.getWidth(),win.getHeight());
        drawObjects();
    }
    else
        drawMultiCam();

    win.SwapBuffers();
}

void FinalGame::dispose()
{
    delete cam;
    for(auto m : meshes)
        delete m;
}

void FinalGame::drawObjects()
{
    for(auto m : etc)
        m->VDraw();
    for(auto m : meshes)
        m->VDraw();
    for(auto m : texturizados)
        m->VDraw();
    for(auto m : transparentes)
        m->VDraw();
}

void FinalGame::drawMultiCam()
{
    static Window win;

    glViewport(0,win.getHeight()/2,win.getWidth(),win.getHeight()/2);
    multicams[0]->Update();
    drawObjects();


    glViewport(0,0,win.getWidth(),win.getHeight()/2);
    multicams[1]->Update();

    drawObjects();

}
