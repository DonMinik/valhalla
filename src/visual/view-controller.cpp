#include <SDL2/SDL.h>
#include "view.h"
#include "view-controller.h"

ViewController::ViewController() {

}

ViewController::~ViewController() {

}

void ViewController::init() {
    SDL_Init(SDL_INIT_EVERYTHING);
}

void ViewController::createView() {
    _view = new View();
}

bool ViewController::isExited() {
    SDL_Event event;
    if (SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) {
            return true;
        }
    }
    return false;
}