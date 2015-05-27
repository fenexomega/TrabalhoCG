#include <iostream>
#include "Engine.h"
#include "game/Game.h"
#include "game/BezierTest.h"

using namespace std;

int main()
{
    Engine eng;
    eng.Run(new BezierTest);
    return 0;
}

