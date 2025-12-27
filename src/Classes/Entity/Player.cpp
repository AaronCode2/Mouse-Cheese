#include "Player.hpp"

Player::Player():
    Sprite({100, 100, 100, 100})
{

    image[LEFT] = LoadTexture("../assets/player/space_rat_left.png");
    image[RIGHT] = LoadTexture("../assets/player/space_rat_right.png");

    object.width = image[LEFT].width;
    object.height = image[LEFT].height;
}

Player::~Player() {

#if !__linux__
    UnloadTexture(image[RIGHT]);
    UnloadTexture(image[LEFT]);
#endif

}

void Player::update() {

    deltaTime = GetFrameTime();

    const float speed = 500 * deltaTime;
    Upspeed = 300 * deltaTime;

    velocity = {0, 0};

    if(IsKeyPressed(KEY_W)) {
        upCounter = GetTime();
        jump = true; 
    }
    if(IsKeyPressed(KEY_S)) {
        downCounter = GetTime();
        goDown = true; 
    };

    if(IsKeyDown(KEY_A)) velocity.x -= speed;
    if(IsKeyDown(KEY_D)) velocity.x += speed;

    if((GetTime() - upCounter > 2.0) && jump == true) {
        jumpTimer = 0.0f;
        jump = false;
    }
    
    if(jump) {
        jumpTimer += deltaTime;   
        velocity.y -= std::abs(std::sin(jumpTimer * 1.5f) * 10.0f) * 80 * deltaTime;
    }

    if((GetTime() - downCounter > 2.0) && goDown == true) {
        goDownTimer = 0.0f;
        goDown = false;
    }
    
    if(goDown) {
        goDownTimer += deltaTime;   
        velocity.y += std::abs(std::sin(goDownTimer * 1.5f) * 5.0f) * 80 * deltaTime;
    }

    if(velocity.x < 0) index = LEFT;
    else if(velocity.x > 0) index = RIGHT;

    updateGravity();

    object.x += velocity.x;
    object.y += velocity.y;

    updateHitBox();

    draw(image[index]);
}

void Player::updateGravity() {

#define GRAVITY 300

    velocity.y += GRAVITY * deltaTime;
}

void Player::updateHitBox() {

    if(!index) {
        hitBox = {

            object.x + 20,
            object.y + 15,
            object.width - 75,
            object.height - 15,
        };
    } else {

        hitBox = {

            object.x + 55,
            object.y + 15,
            object.width - 75,
            object.height - 15,
        };        
    }

    //// DrawRectangleRec(hitBox, {255, 0, 0, 100});
}
