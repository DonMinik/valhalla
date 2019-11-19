#include <SDL2/SDL.h>
#include "view.h"
#include "view-controller.h"
#include "events/input.h"
/*
 * View controller that abstracts SDL specific stuff to
 * the game controller.
 */

ViewController::ViewController() {

}

ViewController::~ViewController() {

}

void ViewController::init() {
    SDL_Init(SDL_INIT_EVERYTHING);
}

void ViewController::createView() {
    _view = new View();
    _input = new Input();
}

void ViewController::detectEvents() {
    _input -> beginNewFrame();
    SDL_Event event;
    if(SDL_PollEvent(&event)) {
        if(event.type == SDL_KEYDOWN) {
            if(event.key.repeat == 0) { //checks if key is not held down
                _input->keyDownEvent(event);
            }
        } else if(event.type == SDL_KEYUP) {
            _input -> keyUpEvent(event);
        } else if (event.type == SDL_QUIT) {
            _exited = true;
        }
    }
}

bool ViewController::isExited() {
    if(_exited || _input -> wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
        return true;
    }

    return false;
}