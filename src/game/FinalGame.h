#ifndef FINALGAME_H
#define FINALGAME_H

#include "interfaces/iGame.h"

#include <vector>
#include <glm/glm.hpp>
using glm::vec3;

class Mesh;
class Camera;
class TexMesh;
class FrameBuffer;
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
    std::vector<Mesh*> cameras;
    bool multiView = false;
    Camera* selectedCam;
    Camera* cam;
    Camera* multicams[4];

    FrameBuffer * fb;
    unsigned int camNum;
    unsigned int maxCams = 4;
    void drawObjects();
    void drawMultiCam();
    void picking();
};

#endif // FinalGAME_H
