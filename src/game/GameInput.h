#ifndef GAMEINPUT_H
#define GAMEINPUT_H

#include <vector>
#include "game/ChoosenMesh.h"


class Mesh;

class GameInput
{
private:
    std::vector<Mesh *> m_meshes;
    ChoosenMesh m_cm;
public:
    GameInput(std::vector<Mesh *> meshes);
    void Update();
    ~GameInput();
};

#endif // GAMEINPUT_H
