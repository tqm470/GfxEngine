#pragma once
#include "../Header/Window.hpp"

class Game
{
public:
    Game( Window& wnd );
    Game( const Game& ) = delete;
    Game& operator=( const Game& ) = delete;
    void Go();
private:
    void Update();
    void Draw();
private:
    //stuff
    
};