#include <SDL2/SDL.h>
#include "view.h"


const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;
const char SCREEN_TITLE[] = "Valhalla";
/**
 * View for game action to take place
 */
View::View() {
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &_window, &_renderer);
    SDL_SetWindowTitle(_window, SCREEN_TITLE);
    SDL_Surface* screenSurface = SDL_GetWindowSurface(_window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface -> format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface( _window);
}

View::~View() {
    SDL_DestroyWindow(_window);
}
