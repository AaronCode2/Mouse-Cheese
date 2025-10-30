#pragma once
#include "Entity/Sprite.hpp"
#include "Entity/Player.hpp"
#include "Entity/Asteroid.hpp"
#include "until.hpp"
#include <raylib.h>
#include <vector>

class Game {

    public:

        Game();
        ~Game();
        void start();

    private:

        Player player;

        std::vector<Asteroid> asteroids;

        Texture2D backgroundCheese = LoadTexture("../assets/background_images/horizon.png");
        Texture2D background = LoadTexture("../assets/background_images/sky.png");

        Rectangle objectBackgroundCheeseSrc;
        Rectangle objectBackgroundSrc;

        float timer = 0;
        long long gameTimer = 0;

        bool gameOver = false;

        void gameLoop();
        void loadTextures();

};