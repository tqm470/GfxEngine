#pragma once
#include "Shader.hpp"

class FragmentShader : public Shader
{
public:
    FragmentShader( std::string fileName );
    FragmentShader() = delete;
    void Compile() override;
};