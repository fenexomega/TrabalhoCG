#ifndef FINALGAME_H
#define FINALGAME_H

#include "interfaces/iGame.h"

#include <vector>

class Mesh;
class Camera;
class FinalGame : public iGame
{
public:
    FinalGame();
    ~FinalGame();


    // iFinalGame interface
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

#endif // FinalGAME_H
