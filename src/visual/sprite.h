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

protected:
    float _x, _y;
protected:
    SDL_Rect _sourceRect;
    SDL_Texture* _spriteSheet;
};
#endif //VALHALLA_SPRITE_H
