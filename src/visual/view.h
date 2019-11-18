#ifndef VALHALLA_VIEW_H
#define VALHALLA_VIEW_H

struct SDL_Window;
struct SDL_Renderer;

class View{
public:
    View();
    ~View();
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
};

#endif //VALHALLA_VIEW_H
