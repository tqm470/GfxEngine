#include "../Header/Texture.hpp"
#include "../Header/stb_image.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <fstream>

Texture::Texture( std::string file_path )
{
    glGenTextures( 1, &texture );
    glBindTexture( GL_TEXTURE_2D, texture );

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER );

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    stbi_set_flip_vertically_on_load(true); 
    unsigned char *data = stbi_load( file_path.c_str() , &texWidth, &texHeight, &nrChannels, 0 );
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        throw("failed to load texture.");
    }
    stbi_image_free(data);
}

void Texture::Bind() const
{
    glBindTexture( GL_TEXTURE_2D, texture );
}