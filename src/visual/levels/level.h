#ifndef VALHALLA_LEVEL_H
#define VALHALLA_LEVEL_H

#include <string>
#include "../globals.h"

class View;
struct SDL_Texture;

class Level {
public:
    Level();
    Level(std::string levelName, Vector2D spawnPoint, View* view);
    ~Level();
    void update(int elapsedTime);
    void draw(View* view);
private:
    std::string _levelName;
    Vector2D _spawnPoint;
    Vector2D _levelSize;
    SDL_Texture* _backgroundTexture;

    /**
     * loads the level
     * @param levelName
     * @param view
     */
    void loadLevel(std::string levelName, View* view);
};

#endif //VALHALLA_LEVEL_H
