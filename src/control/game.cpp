#include "game.h"
#include "../visual/view-controller.h"


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
        _viewController -> detectEvents();
        if (_viewController -> isExited()){
            return;
        }
        _viewController -> endFrame();
      }
}


