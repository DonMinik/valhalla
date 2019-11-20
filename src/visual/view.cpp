#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "view.h"
#include "globals.h"


View::View() {
    SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &_window, &_renderer);
    SDL_SetWindowTitle(_window, globals::SCREEN_TITLE);
    SDL_Surface* screenSurface = SDL_GetWindowSurface(_window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface -> format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface( _window);
}

View::~View() {
    SDL_DestroyWindow(_window);
}


SDL_Surface* View::loadImage(const std::string &filePath) {
    if(_spriteSheets.count(filePath) == 0) {
        _spriteSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return _spriteSheets[filePath];
}

void View::drawToSurface(SDL_Texture *texture, SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle) {
    SDL_RenderCopy(_renderer, texture, sourceRectangle, destinationRectangle);
}

void View::render() {
    SDL_RenderPresent(_renderer);
}

void View::clear() {
    SDL_RenderClear(_renderer);
}

SDL_Renderer* View::getRenderer() const {
    return _renderer;
}