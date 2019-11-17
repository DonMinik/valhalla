#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>


const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;

int main() {
    std::cout << "Hello, Valhalla!" << std::endl;



    SDL_Window *window = NULL;

    SDL_Surface *screenSurface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO < 0)) {
        printf("SDL could not be initialized! SDL ERR: &s\n", SDL_GetError());
    } else {
        window = SDL_CreateWindow("Valhalla", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            printf("Window could not be created! SDL ERR: %s\n", SDL_GetError());
        } else {
            screenSurface = SDL_GetWindowSurface(window);
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface ->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);
            SDL_Delay(2000);
        }
    }

    return 0;
}