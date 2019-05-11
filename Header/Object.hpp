#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "TexModel.hpp"
#include "../Header/ShaderProgram.hpp"


class Object
{
public:
    Object( const Model& model );
    Object( const TexModel& model );
    ~Object();
    void BindVAO();
    void SetVBO( const Model& model );
    void SetVBO( const TexModel& model );
    void SetEBO( unsigned int Elements[], int nElements );
    void DrawE( ShaderProgram render );
    void DrawA( ShaderProgram render );
private:
    const Model& model;
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
};