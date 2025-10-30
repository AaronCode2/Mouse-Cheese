#include "Asteroid.hpp"

Texture2D Asteroid::images[4];

Asteroid::Asteroid():
    Sprite((Rectangle) 
        {
            GetRandomValue(0, 1) ? -100.0f : GetScreenWidth() + 100.0f,
            GetRandomValue(0, 1) ? -100.0f : GetScreenHeight() + 100.0f,
            100, 100
        }
    )
{

    this->velocity = {

        (float) GetRandomValue(-600, 600),
        (float) GetRandomValue(-600, 600)
    };
    this->type = (Asteroid_Type) GetRandomValue(0, 3);
}

void Asteroid::update() {

    object.x += velocity.x * GetFrameTime();
    object.y += velocity.y * GetFrameTime();

    draw2(images[(int) type], rotation); 
    updateHitBox();

}

void Asteroid::updateHitBox() {

    switch(type) {

        case Asteroid_Type::BROCALLIA:

            hitBox = {

                object.x,
                object.y,
                object.width - 60,
                object.height
            };
            break;

        case Asteroid_Type::TINY_CHEESE_LUMP:

            hitBox = {

                object.x + 5,
                object.y + 5,
                object.width - 30,
                object.height - 40
            };
            break;        

        case Asteroid_Type::MID_CHEESE_LUMP:

            hitBox = {

                object.x + 10,
                object.y,
                object.width - 50,
                object.height - 40
            };
            break;
            
        case Asteroid_Type::BIG_CHEESE_LUMP:

            hitBox = {

                object.x,
                object.y,
                object.width - 40,
                object.height - 40
            };
            break;
    }

    //// DrawRectanglePro(hitBox, {hitBox.width / 2, hitBox.height / 2}, rotation, {255, 0, 0, 100});
}
