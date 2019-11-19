
#ifndef VALHALLA_GAME_H
#define VALHALLA_GAME_H

class View;
class ViewController;

class Game {
public:
    Game();
    ~Game();

private:
    void gameLoop();
    void draw(View &graphics);
    void update(float elapsedTime);
    ViewController* _viewController;
};

#endif //VALHALLA_GAME_H
