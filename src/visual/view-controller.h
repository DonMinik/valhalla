
#ifndef VALHALLA_VIEW_CONTROLLER_H
#define VALHALLA_VIEW_CONTROLLER_H

class View;

class ViewController {
public:
    ViewController();
    ~ViewController();


    void init();
    void createView();

    bool isExited();
private:
    View* _view;
};

#endif //VALHALLA_VIEW_CONTROLLER_H
