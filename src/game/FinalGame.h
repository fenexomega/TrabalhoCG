#ifndef FINALGAME_H
#define FINALGAME_H

#include "interfaces/iGame.h"

#include <vector>

class Mesh;
class Camera;
class TexMesh;
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
    std::vector<Mesh*> transparentes;
    std::vector<TexMesh*> texturizados;
    std::vector<Mesh*> etc;
    bool multiView = false;
    Camera* selectedCam;
    Camera* cam;

    Camera* multicams[4];
    unsigned int camNum;
    unsigned int maxCams = 2;
    void drawObjects();
    void drawMultiCam();
};

#endif // FinalGAME_H
