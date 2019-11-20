#ifndef VALHALLA_VIEW_H
#define VALHALLA_VIEW_H

#include <map>
#include <string>
struct SDL_Window;
struct SDL_Renderer;

/**
 * View for game action to take place
 */
class View{
public:
    View();
    ~View();

    SDL_Surface* loadImage(const std::string &filePath);
    void drawToSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
    void render();
    void clear();

    SDL_Renderer* getRenderer() const;
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;

    std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif //VALHALLA_VIEW_H
