
#ifndef VALHALLA_GAME_H
#define VALHALLA_GAME_H

class View;

class Game {
public:
    Game();
    ~Game();

private:
    void gameLoop();
    void draw(View &graphics);
    void update(float elapsedTime);
};

#endif //VALHALLA_GAME_H
