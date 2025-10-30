#pragma once
#include <raylib.h>
#include "Sprite.hpp"

enum class Asteroid_Type {

    BIG_CHEESE_LUMP = 0,
    MID_CHEESE_LUMP,
    TINY_CHEESE_LUMP,
    BROCALLIA
};

class Asteroid : public Sprite {


    public:

        Asteroid();

        void update();
        static Texture2D images[4];

        float time = GetTime();
        float getRotation() const { return rotation; };
        Rectangle getHitBox() const { return hitBox; };

    private:

        Rectangle hitBox; 

        Asteroid_Type type;
        Vector2 velocity;

        float rotation = (float) GetRandomValue(1, 360);
        void updateHitBox();
        

};