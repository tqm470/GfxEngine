#include "../Header/FragmentShader.hpp"
#include <iostream>
#include <string>
#include <string.h>

FragmentShader::FragmentShader( std::string fileName )
    :
    Shader(fileName)
{
    shader = glCreateShader( GL_FRAGMENT_SHADER );
    Compile();
}


void FragmentShader::Compile()
{
    const char* texto = text.c_str();
    glShaderSource( shader, 1, &texto, NULL );
    glCompileShader( shader );
    HandleErrors( shader );
}
