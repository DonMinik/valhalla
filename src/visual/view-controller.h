#ifndef VALHALLA_VIEW_CONTROLLER_H
#define VALHALLA_VIEW_CONTROLLER_H

#include "characters/player.h"

class View;
class Input;

/*
 * View controller that abstracts SDL specific stuff to
 * the game controller.
 */
class ViewController {
public:
    ViewController();
    ~ViewController();


    void init();
    void createView();
    void detectEvents();
    void endFrame();

    void update(float elapsedTime);

    void draw();

    bool isExited();
private:
    View* _view;
    Input* _input;
    Player _playerSprite;

    bool _exited;
    int _lastUpdateTime;

};

#endif //VALHALLA_VIEW_CONTROLLER_H
