#include "GameInput.h"

#include "graphics/Mesh.h"
#include "input/sysInput.h"

GameInput::GameInput(std::vector<Mesh *> meshes)
{
    m_meshes = meshes;
}

void GameInput::Update()
{
    static int i = 0;
    if(sysInput::isKeyDown(SDL_SCANCODE_PAGEDOWN))
        i = (i+1)%m_meshes.size();
    if(sysInput::isKeyDown(SDL_SCANCODE_PAGEUP))
        i = (i-1) < 0 ? m_meshes.size() - 1 : (i-1);

    m_cm.Update(m_meshes.at(i),i);
}

GameInput::~GameInput()
{

}

