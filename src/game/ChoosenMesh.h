#ifndef CHOOSENMESH_H
#define CHOOSENMESH_H

class Mesh;

class ChoosenMesh
{
private:
    enum MODE{
    TRANSLATE,SCALE,ROTATE,NONE};
    Mesh *m_oldMesh;
    void doTranslate(Mesh* mesh);
    void doRotate(Mesh* mesh);
    void doScale(Mesh* mesh);

public:
    ChoosenMesh();
    void Update(Mesh* mesh, int i);
    ~ChoosenMesh();
};

#endif // CHOOSENMESH_H
