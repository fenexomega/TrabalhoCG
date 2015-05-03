#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>
using glm::vec4;

class Light
{
private:
    vec4 m_dir;
public:
    Light(vec4 dir);
    ~Light();
    vec4 dir() const;
    void setDir(const vec4 &dir);
};

#endif // LIGHT_H
