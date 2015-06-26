#ifndef MONTANHARUSSA_H
#define MONTANHARUSSA_H

#include "interfaces/iGame.h"

#include <vector>

class Cylinder;
class iSpline;
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
    std::vector<Mesh*> etc[2];

    Cylinder* _cylinder;
    int _currentCurveNbr = 0;
    iSpline* _currentCurve;
    iSpline* curves[2];
    Camera* cam;
};

#endif // GAME_H
