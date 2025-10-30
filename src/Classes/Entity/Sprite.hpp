#pragma once
#include <raylib.h>
#include <string>

class Sprite {

    public:

        Sprite(Rectangle object);
    
        void update();
    
        Rectangle object = {0, 0, 0, 0};
        Texture2D image = {0};

    protected:

        void draw(Texture2D image);
        void draw2(Texture2D image, float rotation);
};