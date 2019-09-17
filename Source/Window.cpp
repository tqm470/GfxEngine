#include "../Header/Window.hpp"
#include <exception>

Window::Window( const int width, const int height, const char* name )
    :
    width( width ),
    height( height )
{
    glfwInit();
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint( GLFW_RESIZABLE, false );
    window = glfwCreateWindow( this->width, this->height, name, nullptr, nullptr );
    if( window == nullptr )
    {
        throw( "Falha ao criar a janela!" );
        glfwTerminate();
    }
    glfwMakeContextCurrent( window );
    if( !gladLoadGLLoader( (GLADloadproc) glfwGetProcAddress ) )
    {
        throw( "Falha ao iniciar o glad! ");
    }
    glViewport( 0, 0, width, height );
    glEnable( GL_DEPTH_TEST );
}

int Window::GetHeight() const
{
    return height;
}

int Window::GetWidth() const
{
    return width;
}

GLFWwindow* Window::GetWindowPtr()
{
    return window;
}

bool Window::ProcInput() const
{
    if( glfwGetKey( window, GLFW_KEY_ESCAPE ) == GLFW_PRESS )
        glfwSetWindowShouldClose( window, true );

    if( glfwGetKey( window, GLFW_KEY_ENTER ) == GLFW_PRESS )
        glfwSetWindowShouldClose( window, true );

    if( glfwWindowShouldClose( window ) )
        return false;

    return true;
}

void Window::SwapBuffer() const
{
    glfwSwapBuffers( window );
}

int Window::GetKey( int key ) const
{
    return glfwGetKey( window, key );
}

Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}