#ifndef VALHALLA_GAME_H
#define VALHALLA_GAME_H

class View;
class ViewController;


/*
 * controller that keeps the game running
 */
class Game {
public:
    Game();
    ~Game();

private:
    void gameLoop();
    ViewController* _viewController;
};

#endif //VALHALLA_GAME_H
