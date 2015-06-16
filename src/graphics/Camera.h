#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>


using glm::vec3;
using glm::mat4;

class Camera
{
private:
    vec3 eye,center,up;
    mat4 view,proj;
    GLuint projAttrib,viewAttrib;
    GLfloat rotationX{},rotationY{}; //in rads
    GLfloat m_FOV;
    void Rotate();
public:
    void Update();
    void Translate(GLfloat x, GLfloat y,GLfloat z);
    void RotateY(GLfloat angle);
    void setPos(vec3 pos);
    mat4 changePerspective();

    void Move(GLfloat right, GLfloat up, GLfloat front);
    Camera(vec3 _eye, vec3 _center, vec3 _up, GLfloat FOV);

    ~Camera();
    void Translate(glm::vec3 vec);
    void RotateX(GLfloat angle);
    GLfloat FOV() const;
    void setFOV(const GLfloat &FOV);
};
#endif // CAMERA_H
