
#ifndef VALHALLA_VIEW_CONTROLLER_H
#define VALHALLA_VIEW_CONTROLLER_H

class View;
class Input;

class ViewController {
public:
    ViewController();
    ~ViewController();


    void init();
    void createView();
    void detectEvents();

    bool isExited();
private:
    View* _view;
    Input* _input;
    bool _exited;
};

#endif //VALHALLA_VIEW_CONTROLLER_H
