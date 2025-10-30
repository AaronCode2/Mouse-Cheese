#include "App.hpp"
#include "Classes/Game.hpp"
#include <raylib.h>

void App::runApp() {

    
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    
    InitWindow(1000, 800, "Mouse Cheeeeeeeeeeeeese!");
    Image image = LoadImage("../Assets/asteroids/cheeselump3.png");
    SetWindowIcon(image);
    UnloadImage(image);
    
    MaximizeWindow();

    Game newGame;
    newGame.start();
}