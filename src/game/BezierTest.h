#ifndef BEZIERTEST_H
#define BEZIERTEST_H

#include "interfaces/iGame.h"

#include <vector>

class Mesh;
class Camera;
class BezierTest : public iGame
{
public:
    BezierTest();
    ~BezierTest();


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
