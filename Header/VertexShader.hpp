#pragma once
#include "Shader.hpp"

class VertexShader : public Shader
{
public:
    VertexShader( std::string fileName );
    VertexShader() = delete;
    void Compile() override;
};