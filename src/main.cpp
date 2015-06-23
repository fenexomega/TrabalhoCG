#include <iostream>
#include <game/FinalGame.h>
#include <game/MontanhaRussa.h>
#include "Engine.h"
#include "game/Game.h"
#include "game/BezierTest.h"

using namespace std;

int main()
{
    Engine eng;
    eng.Run(new FinalGame);
    return 0;
}

