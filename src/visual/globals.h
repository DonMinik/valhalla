#ifndef VALHALLA_GLOBALS_H
#define VALHALLA_GLOBALS_H

/**
 * gloabal settings
 */
namespace globals {
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 960;
    const char SCREEN_TITLE[] = "Valhalla";
    const int SPRITE_SCALE = 1;
}


enum Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

struct Vector2D {
    int x,y;

    Vector2D():
        x(0), y(0)
    {}
    Vector2D(int x, int y):
        x(x), y(y)
    {}
};
#endif //VALHALLA_GLOBALS_H
