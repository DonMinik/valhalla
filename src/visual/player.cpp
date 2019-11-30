#include "player.h"
#include "view.h"

namespace player_constants {
    const float WALK_SPEED = 0.2f;
    const std::string IDLE_LEFT = "idle_left";
    const std::string IDLE_RIGHT = "idle_right";
    const std::string RUN_LEFT = "run_left";
    const std::string RUN_RIGHT = "run_right";
}

Player::Player() {}

Player::Player(View* view, float x, float y) :
    AnimatedSprite(view, "../resources/sprites/player.png", 0, 0, 250, 250, x, y, 100)
{
    setupAnimations();
    playAnimation(player_constants::IDLE_LEFT);
}

void Player::setupAnimations() {
    addAnimation(1, 0, 500, player_constants::IDLE_LEFT, 250, 250, Vector2D(0,0));
    addAnimation(1, 0, 250, player_constants::IDLE_RIGHT, 250, 250, Vector2D(0,0));
    addAnimation(3, 0, 500, player_constants::RUN_LEFT, 250, 250, Vector2D(0,0));
    addAnimation(3, 0, 250, player_constants::RUN_RIGHT, 250, 250, Vector2D(0,0));
}

void Player::onAnimationDone(std::string currentAnimation) {

}

void Player::moveLeft() {
    _dx = -player_constants::WALK_SPEED;
    playAnimation(player_constants::RUN_LEFT);
    _direction = LEFT;
}

void Player::moveRight() {
    _dx = player_constants::WALK_SPEED;
    playAnimation(player_constants::RUN_RIGHT);
    _direction = RIGHT;
}

void Player::stopMoving() {
    _dx = 0.0f;
    playAnimation(_direction == RIGHT ? player_constants::IDLE_RIGHT : player_constants::IDLE_LEFT);
}

void Player::update(float elapsedTime) {
    _x += _dx * elapsedTime;
    AnimatedSprite::update(elapsedTime);
}

void Player::draw(View* view) {
    AnimatedSprite::draw(view, _x, _y);
}