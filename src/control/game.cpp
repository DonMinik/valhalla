
#include "game.h"
#include "../visual/view-controller.h"

/*
 * controller that keeps the game running
 */

Game::Game() {
    _viewController = new ViewController();
    _viewController -> init();

    gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
    _viewController -> createView();

    while(true){
        _viewController ->detectEvents();
        if (_viewController ->isExited()){
            return;
        }
      }
}

void Game::draw(View &view) {

}

void Game::update(float elapsedTime) {

}

