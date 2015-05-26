#ifndef GAME_H
#define GAME_H

#include "interfaces/iGame.h"

#include <vector>

class Mesh;
class Camera;
class Game : public iGame
{
public:
    Game();
    ~Game();


    // iGame interface
public:
    void init();
    void update(double delta);
    void pause();
    void draw(double delta);
    void dispose();

private:
    std::vector<Mesh*> meshes;
    std::vector<Mesh*> sombras;
    std::vector<Mesh*> etc;

    Camera* cam;
};

#endif // GAME_H
