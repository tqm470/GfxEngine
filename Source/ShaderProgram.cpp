#include "../Header/ShaderProgram.hpp"


ShaderProgram::ShaderProgram( VertexShader vs, FragmentShader fs )
{
    shaderProgram = glCreateProgram();
    glAttachShader( shaderProgram, vs );
    glAttachShader( shaderProgram, fs );
    Compile();
}

void ShaderProgram::Compile()
{
    glLinkProgram( shaderProgram );
    int sucess;
    char* infoLog = (char*) malloc( 512 );
	glGetProgramiv( shaderProgram, GL_LINK_STATUS, &sucess );
	if ( !sucess )
	{
		glGetProgramInfoLog( shaderProgram, 512, NULL, infoLog );
		throw( infoLog );
    }
}

void ShaderProgram::Use()
{
    glUseProgram( shaderProgram );
}

int ShaderProgram::GetProgram()
{
    return shaderProgram;
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram( shaderProgram );
}