#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "../Header/Window.hpp"
#include "../Header/ShaderProgram.hpp"
#include "../Header/Object.hpp"
#include "../Header/Texture.hpp"
#include "stdlib.h"

int main( int argc, char* argv[] )
{

    try
    {
        Window janela( 800, 600, "minha janela" );
        ShaderProgram gfx(
            VertexShader( "Resources/shader/basicVertexShader.1.glsl" ),
            FragmentShader( "Resources/shader/basicFragmentShader.1.glsl" )
        );

        Texture tex( "Resources/textures/doge.png" );
        TexModel quadrado( "Resources/models/cube.model" );
        Object objeto( quadrado );

        srand( time(NULL) );
        glm::vec3 obj1( static_cast<float>( (rand() % 50) - 25  ) / 10,
                        static_cast<float>( (rand() % 50) - 25  ) / 10,
                        static_cast<float>( rand() % 60 * -1) / 10.0f );

        glm::vec3 obj2( static_cast<float>( (rand() % 50) - 25  ) / 10,
                        static_cast<float>( (rand() % 50) - 25  )  / 10,
                        static_cast<float>( rand() % 60 * -1) / 10.0f );

        glm::vec3 obj3( static_cast<float>( (rand() % 50) - 25  ) / 10,
                        static_cast<float>( (rand() % 50) - 25  ) / 10,
                        static_cast<float>( rand() % 60 * -1) / 10.0f );


        glm::mat4 model = glm::mat4( 1.0f );

        glm::mat4 view = glm::mat4( 1.0f );
        view = glm::translate(view, glm::vec3( 0.0f, 0.0f, -3.0f ));

        glm::mat4 projection = glm::mat4( 1.0f );
        projection = glm::perspective( glm::radians( 45.0f ), 
        static_cast<float>( janela.GetWidth() ) / static_cast<float>( janela.GetHeight() )
        , 0.1f, 100.0f );


        //camera bullshit
        // glm::vec3 camPos = glm::vec3( 0.0f, 0.0f, 3.0f );
        // glm::vec3 camTarget = glm::vec3( 0.0f, 0.0f, 0.0f );
        // glm::vec3 camDir = glm::normalize( camPos - camTarget );    
        // glm::vec3 camRight = glm::normalize( glm::cross( glm::vec3( 0.0f, 1.0f, 0.0f ), camDir ) );
        // glm::vec3 camUp = glm::cross( camDir, camRight );


        glm::vec3 camPos = glm::vec3( 0.0f, 0.0f, 3.0f );
        glm::vec3 camDir = glm::vec3( 0.0f, 0.0f, 0.0f );
        

        //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
        while( janela.ProcInput() )
        {
            //camera stuff
            view = glm::lookAt( camPos, camDir, glm::vec3( 0.0f, 1.0f, 0.0f ) );



            glfwPollEvents();
            janela.ProcInput();
            if(janela.GetKey( GLFW_KEY_UP ) == GLFW_PRESS )
            {
                camPos += glm::vec3( 0.0f, 0.0f, -1.0f );
                camDir += glm::vec3( 0.0f, 0.0f, 1.0f );
            }
            if(janela.GetKey( GLFW_KEY_DOWN ) == GLFW_PRESS )
            {
                camPos += glm::vec3( 0.0f, 0.0f, 1.0f );
                camDir += glm::vec3( 0.0f, 0.0f, -1.0f );
            }
            if(janela.GetKey( GLFW_KEY_LEFT ) == GLFW_PRESS )
            {
                camPos += glm::vec3( -0.1f, 0.0f, 0.0f );
                camDir += glm::vec3( -0.1f, 0.0f, 0.0f );
            }
            if(janela.GetKey( GLFW_KEY_RIGHT ) == GLFW_PRESS )
            {
                camPos += glm::vec3( 0.1f, 0.0f, 0.0f );
                camDir += glm::vec3( 0.1f, 0.0f, 0.0f );
            }
            if(janela.GetKey( GLFW_KEY_A ) == GLFW_PRESS )
            {
                //camPos += glm::vec3( 0.1f, 0.0f, 0.0f );
                camDir += glm::vec3( -0.1f, 0.0f, 0.0f );
            }
            if(janela.GetKey( GLFW_KEY_D ) == GLFW_PRESS )
            {
                //camPos += glm::vec3( 0.1f, 0.0f, 0.0f );
                camDir += glm::vec3( 0.1f, 0.0f, 0.0f );
            }
            if(janela.GetKey( GLFW_KEY_W ) == GLFW_PRESS )
            {
                //camPos += glm::vec3( 0.1f, 0.0f, 0.0f );
                camDir += glm::vec3( 0.0f, 0.1f, 0.0f );
            }
            if(janela.GetKey( GLFW_KEY_S ) == GLFW_PRESS )
            {
                //camPos += glm::vec3( 0.1f, 0.0f, 0.0f );
                camDir += glm::vec3( 0.0f, -0.1f, 0.0f );
            }


            {
                //model = glm::rotate(model, (float)glfwGetTime() * glm::radians( 0.1f ), glm::vec3( 0.5f, 1.0f, 0.0f ) );
                unsigned int modelLoc = glGetUniformLocation( gfx.GetProgram(), "model" );
                glUniformMatrix4fv( modelLoc, 1, GL_FALSE, glm::value_ptr( model ) );
            }
            {
                unsigned int viewLoc = glGetUniformLocation( gfx.GetProgram(), "view" );
                glUniformMatrix4fv( viewLoc, 1, GL_FALSE, glm::value_ptr( view ) );
            }
            {
                unsigned int projectionLoc = glGetUniformLocation( gfx.GetProgram(), "projection" );
                glUniformMatrix4fv( projectionLoc, 1, GL_FALSE, glm::value_ptr( projection ) );
            }

            tex.Bind();

            unsigned int modelLoc = glGetUniformLocation( gfx.GetProgram(), "model" );
            glUniformMatrix4fv( modelLoc, 1, GL_FALSE, glm::value_ptr( 
                glm::rotate( glm::translate( model, obj1 ), (float)glfwGetTime() * glm::radians( 30.1f ) * 100, glm::vec3( 0.5f, 1.0f, 0.0f ) ) )
            );
            objeto.DrawA( gfx );

            glUniformMatrix4fv( modelLoc, 1, GL_FALSE, glm::value_ptr( 
                glm::rotate( glm::translate( model, obj2 ), (float)glfwGetTime() * glm::radians( 40.1f ), glm::vec3( -0.5f, -1.0f, 0.0f ) ) )
            );
            objeto.DrawA( gfx );

            glUniformMatrix4fv( modelLoc, 1, GL_FALSE, glm::value_ptr( 
                glm::rotate( glm::translate( model, obj3 ), (float)glfwGetTime() * glm::radians( 20.1f ), glm::vec3( 1.5f, 1.5f, 0.0f ) ) )
            );
            objeto.DrawA( gfx );


            janela.SwapBuffer();
            glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
            glClear( GL_COLOR_BUFFER_BIT );
            glClear( GL_DEPTH_BUFFER_BIT );
        }
    }
    catch( const char* e )
    {
        std::cout << "Erro: " << e << std::endl;
    }
    catch( char* e )
    {
        std::cout << "Erro: " << e << std::endl;
    }
    return 0;
}