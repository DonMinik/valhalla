#ifndef VALHALLA_PLAYER_H
#define VALHALLA_PLAYER_H

#include "animated-sprite.h"
#include  <string>
#include "globals.h"

class View;

class Player: public AnimatedSprite {
public:
    Player();
    Player(View* view, float x, float y);
    void draw(View* view);
    void update(float elapsedTime);

    /**
     * moves player left by -dx
     */
    void moveLeft();
    /**
     * moves player right by dx
     */
    void moveRight();
    /**
     * stops movement
     */
    void stopMoving();

    virtual void onAnimationDone(std::string currentAnimation);
    virtual void setupAnimations();

private:
    float _dx, dy; //delta of position
    Direction _direction;
};

#endif //VALHALLA_PLAYER_H
