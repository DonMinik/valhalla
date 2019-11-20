#ifndef VALHALLA_SPRITE_H
#define VALHALLA_SPRITE_H

#include <SDL2/SDL.h>
#include <string>
class View;


/**
 * class that defines basic sprite properties
 */
class Sprite {
public:
    Sprite();
    Sprite(View* view, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
    virtual ~Sprite();
    virtual void update();
    void draw(View* view, int x, int y);

private:
    SDL_Rect _sourceRect;
    SDL_Texture* _spriteSheet;

    float _x, _y;
};
#endif //VALHALLA_SPRITE_H
