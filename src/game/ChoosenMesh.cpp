#include "ChoosenMesh.h"

#include "graphics/Mesh.h"
#include "utils/Logger.h"
#include "input/sysInput.h"
#define VROT 1.0f


void ChoosenMesh::doTranslate(Mesh *mesh)
{
    if(sysInput::isKeyDown(SDL_SCANCODE_I))
    {
        mesh->transform()->translate(vec3(0,1.0f,0));
    }
    if(sysInput::isKeyDown(SDL_SCANCODE_K))
    {
        mesh->transform()->translate(vec3(0,-1.0f,0));
    }
    if(sysInput::isKeyDown(SDL_SCANCODE_J))
    {
        mesh->transform()->translate(vec3(-1.0f,0,0));
    }
    if(sysInput::isKeyDown(SDL_SCANCODE_L))
    {
        mesh->transform()->translate(vec3(1.0f,0,0));

    }
    if(sysInput::isKeyDown(SDL_SCANCODE_U))
    {
        mesh->transform()->translate(vec3(0,0,-1.0f));
    }
    if(sysInput::isKeyDown(SDL_SCANCODE_O))
    {
        mesh->transform()->translate(vec3(0,0,1.0f));
    }

}

void ChoosenMesh::doRotate(Mesh *mesh)
{
    if(sysInput::isKeyPressed(SDL_SCANCODE_I))
    {
        mesh->transform()->rotate(VROT,vec3(0,1.0f,0));
    }
    if(sysInput::isKeyPressed(SDL_SCANCODE_K))
    {
        mesh->transform()->rotate(VROT,vec3(0,-1.0f,0));
    }
    if(sysInput::isKeyPressed(SDL_SCANCODE_J))
    {
        mesh->transform()->rotate(VROT,vec3(-1.0f,0,0));
    }
    if(sysInput::isKeyPressed(SDL_SCANCODE_L))
    {
        mesh->transform()->rotate(VROT,vec3(1.0f,0,0));
    }
    if(sysInput::isKeyPressed(SDL_SCANCODE_U))
    {
        mesh->transform()->rotate(VROT,vec3(0,0,-1.0f));
    }
    if(sysInput::isKeyPressed(SDL_SCANCODE_O))
    {
        mesh->transform()->rotate(VROT,vec3(0,0,1.0f));
    }
}

void ChoosenMesh::doScale(Mesh *mesh)
{
    if(sysInput::isKeyPressed(SDL_SCANCODE_I))
    {
        mesh->transform()->scale(vec3(1.0f,1.1f,1.0f)); return;
    }
    if(sysInput::isKeyPressed(SDL_SCANCODE_K))
    {
        mesh->transform()->scale(vec3(1.0f,0.9f,1.0f)); return;
    }
    if(sysInput::isKeyPressed(SDL_SCANCODE_J))
    {
        mesh->transform()->scale(vec3(1.0f,0.9f,1.0f)); return;
    }
    if(sysInput::isKeyPressed(SDL_SCANCODE_L))
    {
        mesh->transform()->scale(vec3(1.1f,1.0f,1.0f)); return;
    }
    if(sysInput::isKeyPressed(SDL_SCANCODE_U))
    {
        mesh->transform()->scale(vec3(1.0f,1.0f,0.9f)); return;
    }
    if(sysInput::isKeyPressed(SDL_SCANCODE_O))
    {
        mesh->transform()->scale(vec3(1.0f,1.0f,1.1f)); return;
    }
}

ChoosenMesh::ChoosenMesh()
{
    m_oldMesh = nullptr;
}

void ChoosenMesh::Update(Mesh *mesh, int i)
{
    static MODE mode = NONE;
    if(m_oldMesh != mesh)
    {
        mesh->changeColor(vec3(1.0f,1.0f,1.0f));
        if(m_oldMesh )
            m_oldMesh->changeColor(vec3(1.0f,1.0f,1.0f),true);
        m_oldMesh = mesh;
        LOG("Escolhido -> " << i);
    }

    if(sysInput::isKeyDown(SDL_SCANCODE_T))
    {
        LOG("Modo Translate");
        if(mode == TRANSLATE)
        {
            mode = NONE;
            LOG("Desativado");
        }
        else
        {
            mode = TRANSLATE;
            LOG("Ativado");

        }
    }

    if(sysInput::isKeyDown(SDL_SCANCODE_Y))
    {
        LOG("Modo Scale");

        if(mode == SCALE)
        {
            mode = NONE;
            LOG("Desativado");
        }
        else
        {
            mode = SCALE;
            LOG("Ativado");

        }
    }
    if(sysInput::isKeyDown(SDL_SCANCODE_R))
    {
        LOG("Modo Rotate");

        if(mode == ROTATE)
        {
            mode = NONE;
            LOG("Desativado");
        }
        else
        {
            mode = ROTATE;
            LOG("Ativado");

        }
    }
    switch(mode)
    {
    case TRANSLATE:
        doTranslate(mesh);
        break;
    case ROTATE:
        doRotate(mesh);
        break;
    case SCALE:
        doScale(mesh);
        break;

    }


    
}

ChoosenMesh::~ChoosenMesh()
{

}

