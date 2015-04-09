#include "Game.h"

#include "graphics/Mesh.h"

#include "graphics/Program.h"
#include "graphics/Camera.h"

#include "input/sysInput.h"
#include "objects/Arrow.h"
#include "objects/CoordinateArrows.h"

Game::Game()
{

}

Game::~Game()
{

}



void Game::init()
{
	glEnable(GL_DEPTH_TEST);
    std::vector<float> vao = {
        -5.5f,0.5f,0.0f,
        -5.5f,-0.5f,0.0f,
        5.5f,-0.5f,0.0f,
        5.5f,0.5f,0.0f,
    };

/*      std::vector<float> colors = {
         1.0f,0.0f,0.0f,
         0.0f, 1.0f,0.0f,
        0.0f,0.0f,1.0f,
        1.0f,1.0f,1.0f,
    };
	*/

    std::vector<GLuint> elements = {
        0,1,2,
        2,3,0

    };



    meshes.push_back(new Mesh(vao,glm::vec3(0.5,0,0),elements));
    meshes.push_back(new CoordinateArrows(vec3(0,0,1.0f)));

    Program *p = new Program;
    p->AttachShader(new Shader("gamev.glsl",Shader::VERTEX_SHADER));
    p->AttachShader(new Shader("gamef.glsl",Shader::FRAGMENT_SHADER));
    p->BindFragDataLocation("finalColor",0);

    p->Link();
    p->Use();

    p->PrintActiveVertexInput();
    p->PrintActiveUniforms();

    cam = new Camera(vec3(0,0,1.0f),vec3(0,0,0),vec3(0,1,0),p,70.0f);


}

void Game::update(double delta)
{
    cam->Update();


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

    if(sysInput::isKeyDown(SDL_SCANCODE_F5))
    {
        static bool b = true;
        meshes.at(0)->changeColor(glm::vec3(1.0,1.0,1.0),b = !b);

    }
    for(auto m : meshes)
        m->VUpdate();
}

void Game::pause()
{
}

void Game::draw(double delta)
{
    glClearColor(0,0,0,1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for(auto m : meshes)
        m->VDraw();
}

void Game::dispose()
{
    for(auto m : meshes)
       delete m;
}
