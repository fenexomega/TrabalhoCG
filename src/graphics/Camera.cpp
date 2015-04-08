#include "Camera.h"

#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "graphics/Window.h"

#define PI 3.141516f

template<typename T>
inline T CLAMP(T X,T MIN,T MAX)
{
   return (X) > (MAX) ? (MAX) : (X) < (MIN) ? (MIN) : (X);
}
inline double TORAD(double x)
{
	return (PI*(x))/180.0;
}

#define ABS(x)   (x) < 0 ? -(x) : (x)

std::ostream& operator<<(std::ostream& os, glm::vec3 vec)
{

    return os << "(" << vec.x << "," << vec.y << "," << vec.z << ")";
}

void Camera::Rotate()
{
    center = vec3(eye.x + 1*sin(rotationY) ,
                  eye.y - 1.5f*sin(rotationX),
                  eye.z - 1*cos(rotationY));
}

void Camera::Update()
{
    view = glm::lookAt(eye,center,up);
    glUniformMatrix4fv(projAttrib,1,GL_FALSE,glm::value_ptr(proj));
    glUniformMatrix4fv(viewAttrib,1,GL_FALSE,glm::value_ptr(view));

}

void Camera::Translate(GLfloat x, GLfloat y, GLfloat z)
{
    auto vec = glm::vec3(x,y,z);
    eye += vec;
    center += vec;

}

void Camera::Translate(glm::vec3 vec)
{
    eye += vec;
    center += vec;
}


void Camera::RotateY(GLfloat angle)
{
    rotationY += angle;
    Rotate();

}

void Camera::RotateX(GLfloat angle)
{
    rotationX += angle;
	rotationX = CLAMP(rotationX,-PI/2,PI/2);
    Rotate();


}

void Camera::Move(GLfloat right, GLfloat up, GLfloat front )
{
    glm::vec3 distance(-front*(sin(rotationY)) + right*(cos(rotationY)) ,
                       up,
                       front*(cos(rotationY)) + right*(sin(rotationY)) );
    Translate(distance);
}

Camera::Camera(glm::vec3 _eye, glm::vec3 _center, glm::vec3 _up,Program *program, GLfloat FOV)
    : eye(_eye), center(_center),up(_up)
{
    projAttrib = 2;
    viewAttrib = 1;

    view = glm::lookAt(eye,center,up);

    proj = glm::perspective(FOV, Window::getWidth()/(GLfloat)Window::getHeight(),0.1f,100.0f);

    glUniformMatrix4fv(projAttrib,1,GL_FALSE,glm::value_ptr(proj));
    glUniformMatrix4fv(viewAttrib,1,GL_FALSE,glm::value_ptr(view));

}



Camera::~Camera()
{

}
