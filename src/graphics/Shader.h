#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <iostream>
#include <fstream>


using std::fstream;
using std::string;


class Shader
{
private:
	string filename;
	GLchar * compilationErrors;
	unsigned int shaderID;

	void ReadErrors();
	const string ReadContentFromFile(string filename);
    

public:
    enum ShaderType{
        VERTEX_SHADER = GL_VERTEX_SHADER,
        FRAGMENT_SHADER = GL_FRAGMENT_SHADER
    };
	Shader(string filename,ShaderType shaderType);
	
    const int getShaderId();

    const string getCompilationErrors();

	~Shader();
};

#endif
