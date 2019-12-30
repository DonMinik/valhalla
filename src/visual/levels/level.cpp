#include "level.h"
#include "../view.h"

#include <SDL2/SDL.h>

const int LEVEL_BACKGROUND_IMG_SIZE = 512;
Level::Level() {}

Level::Level(std::string levelName, Vector2D spawnPoint, View *view) :
    _levelName(levelName),
    _spawnPoint(spawnPoint),
    _levelSize(Vector2D(0,0))
{
    loadLevel(levelName, view);
}

Level::~Level() {}

void Level::loadLevel(std::string levelName, View *view) {
    _backgroundTexture = SDL_CreateTextureFromSurface(view->getRenderer(), view->loadImage("../resources/sprites/level.png"));
    _levelSize = Vector2D(globals::SCREEN_WIDTH * 2, globals::SCREEN_HEIGHT *2);
}

void Level::update(int elapsedTime) {}

void Level::draw(View *view) {
    SDL_Rect sourceRect = {0, 0, LEVEL_BACKGROUND_IMG_SIZE, LEVEL_BACKGROUND_IMG_SIZE};
    SDL_Rect destRect;
    for (int x = 0; x < _levelSize.x / LEVEL_BACKGROUND_IMG_SIZE; x++) {
        for (int y = 0; y < _levelSize.y /LEVEL_BACKGROUND_IMG_SIZE; y++) {
            destRect.x = x * LEVEL_BACKGROUND_IMG_SIZE;
            destRect.y = y * LEVEL_BACKGROUND_IMG_SIZE;
            destRect.w = LEVEL_BACKGROUND_IMG_SIZE;
            destRect.h = LEVEL_BACKGROUND_IMG_SIZE;
            view->drawToSurface(_backgroundTexture, &sourceRect, &destRect);
        }
    }
}