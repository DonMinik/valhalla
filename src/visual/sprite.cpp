#include "sprite.h"
#include "view.h"
#include "globals.h"

Sprite::Sprite() {}

Sprite::Sprite(View* view, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX,
               float posY) {
    _x = posX;
    _y = posY;

    _sourceRect.x = sourceX;
    _sourceRect.y = sourceY;
    _sourceRect.w = width;
    _sourceRect.h = height;

    _spriteSheet = SDL_CreateTextureFromSurface(view -> getRenderer(), view -> loadImage(filePath));
    if (_spriteSheet == NULL) {
        printf("\nError: Unable to load image \n");
    }
}

Sprite::~Sprite() {}

void Sprite::draw(View* view, int x, int y) {

    /* Todo: update x and y?
     _x = x;
    _y = y; */

    SDL_Rect destinationRectangle = {x, y, _sourceRect.w * globals::SPRITE_SCALE, _sourceRect.h * globals::SPRITE_SCALE};
    view -> drawToSurface(_spriteSheet, &_sourceRect, &destinationRectangle);
}

void Sprite::update() {}