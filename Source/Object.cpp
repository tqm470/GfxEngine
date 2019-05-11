#include "../Header/Object.hpp"
#include <iostream>

Object::Object( const Model& model )
    :
    model(model)
{
    glGenVertexArrays( 1, &VAO );
    BindVAO();
    SetVBO( model );
    glBindVertexArray(0);
}

Object::Object( const TexModel& model )
    :
    model(model)
{
    glGenVertexArrays( 1, &VAO );
    BindVAO();
    SetVBO( (TexModel) model );
    glBindVertexArray(0);
}

Object::~Object()
{
    glDeleteVertexArrays( 1, &VAO );
}

void Object::BindVAO()
{
    glBindVertexArray( VAO );
}

void Object::SetVBO( const Model& model )
{
    BindVAO();
    glGenBuffers( 1, &VBO );
    glBindBuffer( GL_ARRAY_BUFFER, VBO );
    glBufferData( GL_ARRAY_BUFFER, sizeof( float ) * model.nValues , model.vertexData, GL_DYNAMIC_DRAW );
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof( float ) * 3, (void*)0 ); 
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    std::cout << "deu errado dms!" << std::endl;
}

void Object::SetVBO( const TexModel& model )
{
    BindVAO();
    glGenBuffers( 1, &VBO );
    glBindBuffer( GL_ARRAY_BUFFER, VBO );
    glBufferData( GL_ARRAY_BUFFER, sizeof( float ) * model.nValues , model.vertexData, GL_DYNAMIC_DRAW );
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof( float ), (void*)0 ); 
    glVertexAttribPointer( 1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof( float ), (void*)( 3 * sizeof( float ) ) );
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
}

void Object::SetEBO( unsigned int elements[], int nElements )
{
    glGenBuffers( 1, &EBO );
    BindVAO();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( unsigned int ) * nElements, elements, GL_STATIC_DRAW );
    glBindVertexArray(0);
}

void Object::DrawE( ShaderProgram render )
{
    render.Use();
    glBindVertexArray( VAO );
    glDrawElements(GL_TRIANGLES,  model.nVertex, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Object::DrawA( ShaderProgram render )
{
    render.Use();
    glBindVertexArray( VAO );
    glDrawArrays( GL_TRIANGLES, 0, model.nVertex );
    glBindVertexArray( 0 );
}