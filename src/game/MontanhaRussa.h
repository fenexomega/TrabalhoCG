#ifndef MONTANHARUSSA_H
#define MONTANHARUSSA_H

#include "interfaces/iGame.h"

#include <vector>

class Cylinder;
class Spline;
class Mesh;
class Camera;
class MontanhaRussa : public iGame
{
public:
    MontanhaRussa();
    ~MontanhaRussa();


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

    Cylinder* _cylinder;
    Spline* _bspline;
    Camera* cam;
};

#endif // GAME_H
