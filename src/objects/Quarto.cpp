#include "Quarto.h"

#include "objects/Square.h"
#include "objects/Grid.h"

#include <graphics/Shadow.h>
#define LASTOF(VEC) (VEC[VEC.size()-1])

#define TAM_LADRILHO 0.32f
#define ALTURA 2.0f


std::vector<Mesh *> Quarto::meshes() const
{
    return m_meshes;
}
Quarto::Quarto()
{
    m_meshes.push_back(new Square(vec2(9*TAM_LADRILHO,27*TAM_LADRILHO),vec3(1.0f,1.0f,1.0f)) );
    LASTOF(m_meshes)->transform()->rotate(90.0f,1,0,0);

    m_meshes.push_back(new Square(vec2(9*TAM_LADRILHO,27*TAM_LADRILHO),vec3(1.0f,1.0f,1.0f)) );
    LASTOF(m_meshes)->transform()->translate(0,ALTURA,0);
    LASTOF(m_meshes)->transform()->rotate(90.0f,1,0,0);


    m_meshes.push_back(new Grid(vec3(0,0.0001f,0),vec2(TAM_LADRILHO,TAM_LADRILHO),27,
                                vec3(0.f,0.f,0.f)));
    //PAREDES
    m_meshes.push_back(new Square(vec2(27*TAM_LADRILHO,ALTURA),vec3(1.0f,1.0f,1.0f)) );
    LASTOF(m_meshes)->transform()->translate(-9*TAM_LADRILHO/2,ALTURA/2,0);
    LASTOF(m_meshes)->transform()->rotate(90.0f,0,1,0);


    m_meshes.push_back(new Square(vec2(27*TAM_LADRILHO,ALTURA),vec3(1.0f,1.0f,1.0f)) );
    LASTOF(m_meshes)->transform()->translate(9*TAM_LADRILHO/2,ALTURA/2,0);
    LASTOF(m_meshes)->transform()->rotate(-90.0f,0,1,0);

    m_meshes.push_back(new Square(vec2(9*TAM_LADRILHO,ALTURA),vec3(1.0f,1.0f,1.0f)) );
    LASTOF(m_meshes)->transform()->translate(0,ALTURA/2,27*TAM_LADRILHO/2);

    m_meshes.push_back(new Square(vec2(9*TAM_LADRILHO,ALTURA),vec3(1.0f,1.0f,1.0f)) );
    LASTOF(m_meshes)->transform()->translate(0,ALTURA/2,-27*TAM_LADRILHO/2);


    m_meshes.push_back(new Mesh("Rack.obj",vec3(0.2,0.3,0.6)));
    LASTOF(m_meshes)->transform()->rotate(90,0,1,0);
    LASTOF(m_meshes)->transform()->translate(-3,0.5,1.2);

    m_meshes.push_back(new Mesh("Gaming Desk.obj",vec3(0.5f,0.0f,0.3f)));
    LASTOF(m_meshes)->transform()->translate(1.2,-0.025f,2);
    LASTOF(m_meshes)->transform()->rotate(-90,0,1,0);
    LASTOF(m_meshes)->transform()->scale(0.25f,0.25f,0.25f);

    m_meshes.push_back(new Mesh("Bed.obj",vec3(1.0f,0.f,0.3f)));
    LASTOF(m_meshes)->transform()->translate(-0.8f,0.25,3.3f);
    LASTOF(m_meshes)->transform()->rotate(-180,0,1,0);
    LASTOF(m_meshes)->transform()->scale(0.5f,0.5f,0.5f);



    m_meshes.push_back(new Mesh("soccer ball.obj",vec3(0.8f,0.8f,1.0f)));
    LASTOF(m_meshes)->transform()->translate(-0,0.05f,1.2f);
    LASTOF(m_meshes)->transform()->scale(0.001f,0.001f,0.001f);



    m_meshes.push_back(new Shadow
             (LASTOF(m_meshes),
              vec3(0,0,0),Light(vec4(0.0,-1.0,0.0,0.0))));
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


void Quarto::VUpdate()
{
     m_meshes[10]->transform()->rotate(-1.5f,0,1.f,0);
     m_meshes[10]->transform()->translate(0,0,6.0f);

}
