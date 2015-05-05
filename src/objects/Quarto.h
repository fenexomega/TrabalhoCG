#ifndef QUARTO_H
#define QUARTO_H

#include <graphics/Mesh.h>
#include <vector>


class Quarto : public Mesh
{
private:
    std::vector<Mesh*> m_meshes;
public:
    Quarto();

    ~Quarto();

    // Mesh interface
public:
    void VDraw();

    // Mesh interface
public:
    void VUpdate();
    std::vector<Mesh *> meshes() const;
};

#endif // QUARTO_H
