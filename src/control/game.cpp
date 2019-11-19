#include <SDL2/SDL.h>

#include "game.h"
#include "../visual/view.h"

/*
 * controller that keeps the game running
 */
Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    this -> gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
    View view;
    SDL_Event event;

    while(true){
        if (SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT) {
                return;
            }
        }
    }
}

void Game::draw(View &view) {

}

void Game::update(float elapsedTime) {

}

