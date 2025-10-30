#include "Sprite.hpp"

Sprite::Sprite(Rectangle object) {

    this->object = object;
}

void Sprite::update() {
    
    draw(image);
}

void Sprite::draw(Texture2D image) {

    DrawTexture(image, object.x, object.y, WHITE);
}

void Sprite::draw2(Texture2D image, float rotation) {

    DrawTexturePro(
        image, 
        {0, 0, (float) image.width, (float) image.height},
        object,
        {object.width / 2, object.height / 2},
        rotation, WHITE
    );
}
