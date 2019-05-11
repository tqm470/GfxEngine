#pragma once
#include <glad/glad.h>
#include <string>
#include <fstream>

class Shader
{
public:
    Shader( std::string filePath );
    operator int();
    ~Shader();
protected:
    void HandleErrors( int shader );
    virtual void Compile() = 0;
protected:
    int shader;
    std::string text;
};