#pragma once

#include <string>

class Texture 
{
public:
    Texture( std::string file_path );
    void Bind() const;
private:
    unsigned int texture;
    int texWidth, texHeight, nrChannels;
};