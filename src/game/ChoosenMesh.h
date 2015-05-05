#ifndef CHOOSENMESH_H
#define CHOOSENMESH_H

class Mesh;

class ChoosenMesh
{
private:
    Mesh *m_oldMesh;
public:
    ChoosenMesh();
    void Update(Mesh* mesh, int i);
    ~ChoosenMesh();
};

#endif // CHOOSENMESH_H
