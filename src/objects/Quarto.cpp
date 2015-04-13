#include "Quarto.h"

#include "objects/Square.h"
#include "objects/Grid.h"
#define TAM_LADRILHO 0.32f
#define ALTURA 2.0f

Quarto::Quarto()
{
    m_paredes.push_back(new Square(vec2(9*TAM_LADRILHO,27*TAM_LADRILHO),vec3(1.0f,1.0f,1.0f)) );
    m_paredes[0]->transform().rotate(90.0f,1,0,0);
    m_paredes.push_back(new Grid(vec3(0,0.0001f,0),vec2(TAM_LADRILHO,TAM_LADRILHO),27,
                                 vec3(0.f,0.f,0.f)));
    m_paredes.push_back(new Square(vec2(27*TAM_LADRILHO,ALTURA),vec3(1.0f,1.0f,1.0f)) );
    m_paredes[2]->transform().translate(-9*TAM_LADRILHO/2,ALTURA/2,0);
    m_paredes[2]->transform().rotate(90.0f,0,1,0);
    m_paredes.push_back(new Square(vec2(27*TAM_LADRILHO,ALTURA),vec3(1.0f,1.0f,1.0f)) );
    m_paredes[3]->transform().translate(9*TAM_LADRILHO/2,ALTURA/2,0);
    m_paredes[3]->transform().rotate(-90.0f,0,1,0);


}

Quarto::~Quarto()
{
    for(Mesh *m : m_paredes)
        delete m;
}



void Quarto::VDraw()
{
    for(Mesh *m : m_paredes)
        m->VDraw();
}
