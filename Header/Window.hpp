#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
public:
    Window( const int width, const int height, const char* name );
    Window( Window& ) = delete;
    Window() = delete;
    Window& operator=( Window& ) = delete;
    int GetWidth() const;
    int GetHeight() const;
    bool ProcInput() const;
    void SwapBuffer() const;
    int GetKey( int key ) const;
    ~Window();
private:
    GLFWwindow* GetWindowPtr();
private:
    int height;
    int width;
    GLFWwindow* window;
};