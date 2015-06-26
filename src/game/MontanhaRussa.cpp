#include "MontanhaRussa.h"

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
#include <graphics/CatRoll.h>
#include <graphics/Light.h>
#include <graphics/Sphere.h>
#include <graphics/Window.h>
#include "game/GameInput.h"
#include "game/Cylinder.h"
#define TAM_LADRILHO 0.32f
#define ALTURA 2.0f
#define LASTOF(VEC) (VEC[VEC.size()-1])



MontanhaRussa::MontanhaRussa()
{

}

MontanhaRussa::~MontanhaRussa()
{

}



void MontanhaRussa::init()
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
        {0.0f,0.0f,0.0f}, //0
        {0.0f,0.0f,0.0f}, //1
        {1.0f,1.0f,0.0f}, //2
        {2.0f,2.0f,0.0f}, //3
        {3.0f,1.5f,0.0f}, //4
        {4.0f,3.0f,0.0f}, //5
        {5.0f,3.0f,7.0f}, //6
        {5.0f,1.0f,6.0f}, //7
        {5.0f,1.0f,9.0f}, //8
        {5.0f,1.0f,12.0f},
        {5.0f,2.0f,15.0f},
        {5.0f,9.0f,17.0f},
        {5.0f,3.0f,17.0f},
        {7.0f,0.0f,17.0f},
        {7.0f,9.0f,20.0f},
        {7.0f,9.0f,23.0f},
        {7.0f,9.0f,25.0f},
        {2.0f,9.0f,25.0f},
        {2.0f,9.0f,28.0f},
        {3.0f,9.0f,28.0f},
        {5.0f,9.0f,28.0f},
        {7.0f,10.0f,28.0f},
        {8.0f,12.0f,25.0f},
        {7.0f,11.0f,23.0f},
        {6.0f,10.0f,23.0f},
        {0.0f,0.0f,0.0f}, //0
        {1.0f,1.0f,0.0f}, //2
        {2.0f,2.0f,0.0f}, //3











    };

    int numPoints = sizeof(control_points1)/sizeof(float)/3;
    curves[0] = new Spline(control_points1,numPoints,15);
    curves[1] = new CatRoll(control_points1,numPoints,15);
    _currentCurve = curves[0];
//    etc.push_back(new Bezier(control_points,80));
//    etc.push_back(_bspline);
//    etc.push_back(new Box(vec3(0.2f,0.2f,0.2f),glm::vec3(1.0,0,0),vec3()));

    for(int i = 0 ; i < 2 ; ++i)
        for(float u = 1.0f; u <= curves[i]->numCtrlPoints() - 3; u += 1/15.0f)
        {
            _cylinder = new Cylinder(0.5f,0.5f,8.0f,20.0f);
            _cylinder->transform()->setModel(curves[i]->getTransformMatrix(u));
            etc[i].push_back(_cylinder);
        }
//    etc.push_back(new Grid(vec3(0,0,0),vec2(TAM_LADRILHO,TAM_LADRILHO),500,
//                                    vec3(1.f,1.f,1.f)));

    cam = new Camera(vec3(0,0.5,3.0f),vec3(0,0.5,0),vec3(0,1,0),70.0f);

    Light luz {glm::vec3(0,0,1)};


}

void MontanhaRussa::update(double delta)
{

    static float initialU = 1.0f;
    static float u = initialU;
    static float distance;
    static vec3 carPos;
    static float ucar;
    static bool carMoving = true;


    if(carMoving)
    {
        float auxValueForCarPos = 0.5f;

        // controlar a posição da câmera
        if( u >= _currentCurve->numCtrlPoints() - 3)
            u = initialU;
        LOG(int(u));
        auto pos = _currentCurve->getPositionAt(u);
        auto center = pos + _currentCurve->getNextPosition(u);
        auto up = - _currentCurve->getUpPosition(u);

            delete cam;
            cam = new Camera(pos + vec3(0,0.25f,0),center,vec3(0,1,0),70.0f);
        u += 0.01f;
    }
    cam->Update();

//    distance = 1.0f;
//    int i = 0;
//    do
//    {
//        ucar = u + auxValueForCarPos;
//        carPos = _bspline->getPositionAt(ucar);
//        distance = glm::distance(pos,carPos);
//        auxValueForCarPos -= 0.001f;
//        LOG(distance << " | " << i++);



//    }while(distance > 0.5f);


    //mover o carrinho
    etc[_currentCurveNbr][0]->transform()->setModel(_currentCurve->getTransformMatrix(u + 0.5f));



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

    if(sysInput::isKeyDown(SDL_SCANCODE_C))
        carMoving = !carMoving;

    if(sysInput::isKeyDown(SDL_SCANCODE_TAB))
    {
        _currentCurveNbr = (++_currentCurveNbr)%2;
        _currentCurve = curves[_currentCurveNbr];
    }


    if(sysInput::isKeyDown(SDL_SCANCODE_F5))
    {
        static bool b = true;
        meshes.at(0)->changeColor(glm::vec4(1.0,1.0,1.0,1.0f),b = !b);

    }


    for(auto m : meshes)
        m->VUpdate();
    for(auto m : etc[_currentCurveNbr])
        m->VUpdate();
    for(auto m : sombras)
        m->VUpdate();
}

void MontanhaRussa::pause()
{
}

void MontanhaRussa::draw(double delta)
{
    static Window win;
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for(auto m : etc[_currentCurveNbr])
        m->VDraw();
    for(auto m : sombras)
        m->VDraw();
    for(auto m : meshes)
        m->VDraw();
    win.SwapBuffers();
}

void MontanhaRussa::dispose()
{
    for(auto m : meshes)
       delete m;
}
