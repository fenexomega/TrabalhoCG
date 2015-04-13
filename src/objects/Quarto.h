#ifndef QUARTO_H
#define QUARTO_H

#include <graphics/Mesh.h>
#include <vector>


class Quarto : public Mesh
{
private:
    std::vector<Mesh*> m_paredes;
public:
    Quarto();

    ~Quarto();

    // Mesh interface
public:
    void VDraw();
};

#endif // QUARTO_H
