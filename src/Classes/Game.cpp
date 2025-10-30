#include "Game.hpp"

Game::Game() {

    loadTextures();

    objectBackgroundCheeseSrc = {
        0, 0,
        (float) backgroundCheese.width,
        (float) backgroundCheese.height,
    };

    objectBackgroundSrc = {
        0, 0,
        (float) background.width,
        (float) background.height,
    };
}

Game::~Game() {

    UnloadTexture(Asteroid::images[0]);
    UnloadTexture(Asteroid::images[1]);
    UnloadTexture(Asteroid::images[2]);
    UnloadTexture(Asteroid::images[3]);
}

void Game::start() {

    while(!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(GRAY);
            gameLoop();
        EndDrawing();
    }

    CloseWindow();
}

void Game::gameLoop() {

    
    DrawTexturePro(
        background, objectBackgroundSrc,
        {0, 0, (float) GetScreenWidth(), (float) GetScreenHeight()}, {0, 0},
        0, WHITE
    );
    
    DrawTexturePro(
        backgroundCheese, objectBackgroundCheeseSrc,
        {0, 0, (float) GetScreenWidth(), (float) GetScreenHeight()}, {0, 0},
        0, WHITE
    );
    
    DrawText((std::to_string(GetFPS()) + " FPS").c_str(), 10, GetScreenHeight() - 100, 20, GREEN);
    DrawText(std::to_string(gameTimer).c_str(), 10, 10, 100, YELLOW);

    if(gameOver) {

        DrawText("GAME OVER!", (GetScreenWidth() / 2) - 250, GetScreenHeight() / 2, 100, RED);
        DrawText("PRESS [SPACE] TO RETRY!", (GetScreenWidth() / 2) - 250, GetScreenHeight() / 2, 10, RED);
        asteroids.clear();

        if(IsKeyDown(KEY_SPACE)) {

            gameTimer = 0;
            gameOver = false;
        }
        player.setPosition({100, 100});

        return;
    } 

    player.update();
    
    if(GetTime() - timer > 0.1) {

        asteroids.push_back(Asteroid());
        timer = GetTime();
        gameTimer++;
    }
    
    for(auto it = asteroids.begin(); it < asteroids.end(); it++) {

        if(GetTime() - it->time > 20)
            asteroids.erase(it);
    }

    for(auto &asteroid : asteroids) {

        if(CheckCollisionRecsRotated(asteroid.getHitBox(), asteroid.getRotation(), player.getHitBox(), 0))
            gameOver = true;

        asteroid.update();
    }

    if(
        player.getHitBox().y - 50 > GetScreenHeight() ||
        player.getHitBox().y + player.getHitBox().height + 50 < 0 ||
        player.getHitBox().x + player.getHitBox().width + 50 < 0 ||
        player.getHitBox().x - 50 > GetScreenWidth()
    ) gameOver = true;


}

void Game::loadTextures() {

    Asteroid::images[0] = LoadTexture("../assets/asteroids/cheeselump1.png");
    Asteroid::images[1] = LoadTexture("../assets/asteroids/cheeselump2.png");
    Asteroid::images[2] = LoadTexture("../assets/asteroids/cheeselump3.png");
    Asteroid::images[3] = LoadTexture("../assets/asteroids/broccolo.png");
}
