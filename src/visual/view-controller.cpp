#include <SDL2/SDL.h>
#include "view.h"
#include "view-controller.h"
#include "events/input.h"

namespace {
    const int FPS = 50;
    const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}


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
    _playerSprite =  Sprite(_view, "../resources/sprites/player.png", 0, 0, 250, 250, 100, 100);

    draw();
    _lastUpdateTime = SDL_GetTicks();
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

void ViewController::endFrame() {
    const int CURRENT_TIME_MS = SDL_GetTicks();
    int elapsedTimeMS = CURRENT_TIME_MS - _lastUpdateTime;
    update(std::min(elapsedTimeMS, MAX_FRAME_TIME));
    _lastUpdateTime = CURRENT_TIME_MS;

}

void ViewController::update(float elapsedTime) {

}

void ViewController::draw() {
    _view -> clear();
    _playerSprite.draw(_view, 100, 100);

    _view -> render();
}


bool ViewController::isExited() {
    if(_exited || _input -> wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
        return true;
    }

    return false;
}