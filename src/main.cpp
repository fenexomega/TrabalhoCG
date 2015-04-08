#include <iostream>
#include "Engine.h"
#include "game/Game.h"

using namespace std;

int main()
{
    Engine eng;
    eng.Run(new Game);
    return 0;
}

