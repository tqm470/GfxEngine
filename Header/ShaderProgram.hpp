#pragma once
#include "VertexShader.hpp"
#include "FragmentShader.hpp"

class ShaderProgram
{
public:
    ShaderProgram( VertexShader vs, FragmentShader fs );
    int GetProgram();
    ~ShaderProgram();
    void Use();
private:
    void Compile();
private:
    int shaderProgram;
};