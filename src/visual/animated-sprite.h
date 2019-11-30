#ifndef VALHALLA_ANIMATED_SPRITE_H
#define VALHALLA_ANIMATED_SPRITE_H

#include "sprite.h"
#include "globals.h"
#include <string>
#include <map>
#include <vector>
class View;

/**
 * an animated sprite
 */
class AnimatedSprite: public Sprite {
public:
    AnimatedSprite();
    AnimatedSprite(View* view, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate);
    /**
     * plays animation by given name
     * @param animation
     * @param once
     */
    void playAnimation(std::string animation, bool once = false);
    /**
     *  updates the sprite
     * @param elapsedTime
     */
    void update(int elapsedTime);
    /**
     * draws sprite on screen
     * @param view
     * @param x
     * @param y
     */
    void draw(View* view, int x, int y);


protected:
    double _timeToUpdate;
    bool _currentAnimationOnce;
    std::string _currentAnimation;
    /**
     * adds animation to map of animation
     * @param frames
     * @param x
     * @param y
     * @param name
     * @param windth
     * @param heigt
     * @param offset
     * @return
     */
    void addAnimation(int frames, int x, int y, std::string name, int width, int heigt, Vector2D offset);
    /**
     * resets all animations associated with this sprite
     */
    void resetAnimations();
    /**
     * stops current animation
     */
    void stopAnimation();
    /**
     * sets visibility of animated sprite
     * @param visible
     */
    void setVisible(bool visible);
    /**
     * when animation is ends
     * @param currentAnimation
     */
    virtual void onAnimationDone(std::string currentAnimation) = 0;
    /**
      * required method, that sets up all animations
      */
    virtual void setupAnimations() = 0;
private:
    std::map<std::string, std::vector<SDL_Rect>>_animations;
    std::map<std::string, Vector2D> _offsets;

    int _frameIndex;
    double _timeElapsed;
    bool _visible;
};

#endif //VALHALLA_ANIMATED_SPRITE_H
