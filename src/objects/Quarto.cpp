#include "Quarto.h"

#include "objects/Square.h"
#include "objects/Grid.h"
#define LASTOF(VEC) VEC[VEC.size()-1]

#define TAM_LADRILHO 0.32f
#define ALTURA 2.0f

Quarto::Quarto()
{
    m_meshes.push_back(new Square(vec2(9*TAM_LADRILHO,27*TAM_LADRILHO),vec3(1.0f,1.0f,1.0f)) );
    LASTOF(m_meshes)->transform().rotate(90.0f,1,0,0);

    m_meshes.push_back(new Square(vec2(9*TAM_LADRILHO,27*TAM_LADRILHO),vec3(1.0f,1.0f,1.0f)) );
    LASTOF(m_meshes)->transform().translate(0,ALTURA,0);
    LASTOF(m_meshes)->transform().rotate(90.0f,1,0,0);


    m_meshes.push_back(new Grid(vec3(0,0.0001f,0),vec2(TAM_LADRILHO,TAM_LADRILHO),27,
                                vec3(0.f,0.f,0.f)));
    //PAREDES
    m_meshes.push_back(new Square(vec2(27*TAM_LADRILHO,ALTURA),vec3(1.0f,1.0f,1.0f)) );
    LASTOF(m_meshes)->transform().translate(-9*TAM_LADRILHO/2,ALTURA/2,0);
    LASTOF(m_meshes)->transform().rotate(90.0f,0,1,0);


    m_meshes.push_back(new Square(vec2(27*TAM_LADRILHO,ALTURA),vec3(1.0f,1.0f,1.0f)) );
    LASTOF(m_meshes)->transform().translate(9*TAM_LADRILHO/2,ALTURA/2,0);
    LASTOF(m_meshes)->transform().rotate(-90.0f,0,1,0);

    m_meshes.push_back(new Square(vec2(9*TAM_LADRILHO,ALTURA),vec3(1.0f,1.0f,1.0f)) );
    LASTOF(m_meshes)->transform().translate(0,ALTURA/2,27*TAM_LADRILHO/2);

    m_meshes.push_back(new Square(vec2(9*TAM_LADRILHO,ALTURA),vec3(1.0f,1.0f,1.0f)) );
    LASTOF(m_meshes)->transform().translate(0,ALTURA/2,-27*TAM_LADRILHO/2);


    m_meshes.push_back(new Mesh("Rack.obj",vec3(0.2,0.3,0.6)));
    LASTOF(m_meshes)->transform().rotate(90,0,1,0);
    LASTOF(m_meshes)->transform().translate(-3,0.5,1.2);

}

Quarto::~Quarto()
{
    for(Mesh *m : m_meshes)
        delete m;
}



void Quarto::VDraw()
{
    for(Mesh *m : m_meshes)
        m->VDraw();
}
