#include "sysInput.h"


SDL_Event sysInput::e;
glm::vec2 sysInput::coords;

void sysInput::update()
{
    SDL_PollEvent(&e);
    keys = SDL_GetKeyboardState(NULL);


    coords = glm::vec2(0,0);
    if(e.type == SDL_MOUSEWHEEL)
    {
       coords.x = e.wheel.x;
       coords.y = e.wheel.y;
    }
    SDL_PumpEvents();

    int i;
    //TODO Mouse Unput!


    mouseUpKeys.clear();
    for(i = 0; i < 4; i++)
        if(!getMouseButton(i) && (find(mouseCurrentKeys.begin(),mouseCurrentKeys.end(),i) != mouseCurrentKeys.end()) )
            mouseUpKeys.push_back(i);

    mouseDownKeys.clear();
    for(i = 0; i < 4; i++)
        if(getMouseButton(i) && !(find(mouseCurrentKeys.begin(),mouseCurrentKeys.end(),i) != mouseCurrentKeys.end()))
            mouseDownKeys.push_back(i);

    mouseCurrentKeys.clear();
    for(i = 0; i < 4; i++)
        if(getMouseButton(i))
            mouseCurrentKeys.push_back(i);



    upKeys.clear();
    for(i = 0; i < NUM_KEYCODES; i++)
        if(!getKey(i) && (find(currentKeys.begin(),currentKeys.end(),i) != currentKeys.end()) )
            upKeys.push_back(i);

    downKeys.clear();
    for(i = 0; i < NUM_KEYCODES; i++)
        if(getKey(i) && !(find(currentKeys.begin(),currentKeys.end(),i) != currentKeys.end()))
            downKeys.push_back(i);

    currentKeys.clear();
    for(i = 0; i < NUM_KEYCODES; i++)
        if(getKey(i))
            currentKeys.push_back(i);
}

bool sysInput::isKeyUp(int x)
{
    return find(upKeys.begin(),upKeys.end(),x) != upKeys.end();
}

bool sysInput::isKeyDown(int x)
{
    return find(downKeys.begin(),downKeys.end(),x) != downKeys.end();
}

bool sysInput::isKeyPressed(int x)
{
    return find(currentKeys.begin(),currentKeys.end(),x) != currentKeys.end();
}

bool sysInput::isMouseButtonUp(int x)
{
    return find(mouseUpKeys.begin(),mouseUpKeys.end(),x) != mouseUpKeys.end();
}

bool sysInput::isMouseButtonDown(int x)
{
    return find(mouseDownKeys.begin(),mouseDownKeys.end(),x) != mouseDownKeys.end();
}

bool sysInput::isMouseButtonPressed(int x)
{
    return find(mouseCurrentKeys.begin(),mouseCurrentKeys.end(),x) != mouseCurrentKeys.end();
}

bool sysInput::isAnyKeyDown()
{
    for(int i = 0; i < 300; i++)
        if(isKeyPressed(i) || isKeyDown(i))
            return true;
    return false;
}

bool sysInput::getKey(int key)
{
    return keys[key] == 1;
}

glm::vec2 sysInput::getMousePos()
{
    int x,y;
    SDL_GetMouseState(&x,&y);
    glm::vec2 aux(x,y);
    return aux;

}

bool sysInput::getMouseButton(int button)
{
    return SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(button);
}

bool sysInput::UserWannaQuit()
{
    return e.type == SDL_QUIT;
}

glm::vec2 sysInput::getMouseWheel()
{

    return coords;
}

