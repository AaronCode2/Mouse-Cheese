#pragma once
#include <raylib.h>
#include "Sprite.hpp"
#include <math.h>
#include <iostream>

enum direction {
    LEFT,
    RIGHT
};

class Player : public Sprite {

    public:

        Player();
        ~Player();

        void update();

        Vector2 getVelocity() const { return velocity; };
        Rectangle getHitBox() const { return hitBox; };
        void setPosition(Vector2 newPos) { object.x = newPos.x; object.y = newPos.y; };
    private:

        Texture2D image[2];

        Rectangle hitBox;

        Vector2 velocity = {0, 0};
        int index = 0;
        float Upspeed = 0.0f;
        float upCounter = GetTime();
        float downCounter = GetTime();
        float jumpTimer = 0.0f;
        float deltaTime;
        bool jump = false;
        bool goDown = false;
        float goDownTimer = false;
        void updateGravity();
        void updateHitBox();
};