#include "../Header/Shader.hpp"
#include <iostream>

Shader::Shader( std::string fileName )
{
    std::fstream file( fileName, std::fstream::in );
    if( !file.is_open() )
    {
        throw( "Erro ao abrir um shader file!" );
    }
    std::string aux;
    while( file.good() )
    {
        std::getline(file, aux);
        aux.append("\n");
        text.append( std::move( aux ) );
    }
    file.close();
}


void Shader::HandleErrors( int shader )
{
    int sucess;
	char* infoLog = (char*) malloc( 1024 );
    glGetShaderiv( shader, GL_COMPILE_STATUS, &sucess );
    if( !sucess )
    {
        glGetShaderInfoLog( shader, 1024, nullptr, infoLog );
        throw( infoLog );
    }
}

Shader::operator int()
{
    return shader;
}

Shader::~Shader()
{
    glDeleteShader( shader );
}