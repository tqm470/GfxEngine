#include "../Header/VertexShader.hpp"
#include <iostream>
#include <string>
#include <string.h>

VertexShader::VertexShader( std::string fileName )
    :
    Shader(fileName)
{
    shader = glCreateShader( GL_VERTEX_SHADER );
    Compile();
}

void VertexShader::Compile()
{
    const char* texto = text.c_str();
    glShaderSource( shader, 1, &texto, NULL );
    glCompileShader( shader );
    HandleErrors( shader );
}