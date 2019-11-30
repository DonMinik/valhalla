#include "animated-sprite.h"
#include "view.h"
#include "sprite.h"


AnimatedSprite:: AnimatedSprite() {}

AnimatedSprite::AnimatedSprite(View* view, const std::string &filepath, int sourceX, int sourceY,
        int width, int height, float posX, float posY, float timeToUpdate):
    Sprite(view, filepath, sourceX, sourceY, width, height, posX, posY),
    _frameIndex(0),
    _timeToUpdate(timeToUpdate),
    _visible(true),
    _currentAnimationOnce(false),
    _currentAnimation("")
{}

void AnimatedSprite::addAnimation(int frames, int x, int y, std::string name, int width, int heigt, Vector2D offset) {
    std::vector<SDL_Rect> rectangles;
    for (int i = 0; i < frames; i++) {
        SDL_Rect newRectangle = {(i +x)*width, y, width, heigt};
        rectangles.push_back(newRectangle);
    }
    _animations.insert(std::pair<std::string, std::vector<SDL_Rect>>(name, rectangles));
    _offsets.insert(std::pair<std::string, Vector2D>(name, offset));
}

void AnimatedSprite::resetAnimations() {
    _animations.clear();
    _offsets.clear();
}

void AnimatedSprite::playAnimation(std::string animation, bool once) {
    _currentAnimationOnce = once;
    if(_currentAnimation != animation){
        _currentAnimation = animation;
        _frameIndex = 0;
    }
}

void AnimatedSprite::setVisible(bool visible) {
    _visible = visible;
}

void AnimatedSprite::stopAnimation() {
    _frameIndex = 0;
    onAnimationDone(_currentAnimation);
}

void AnimatedSprite::update(int elapsedTime) {
    Sprite::update();

    _timeElapsed += elapsedTime;
    if (_timeElapsed > _timeToUpdate) {
        _timeElapsed -= _timeToUpdate;
        if(_frameIndex < _animations[_currentAnimation].size() -1) {
            _frameIndex++;
        } else {
            if (_currentAnimationOnce == true) {
                setVisible(false);
            }
            _frameIndex = 0;
            onAnimationDone(_currentAnimation);
        }
    }
}

void AnimatedSprite::draw(View* view, int x, int y) {
    if (_visible) {
       SDL_Rect destinationRectangle;
       destinationRectangle.x = x + _offsets[_currentAnimation].x;
       destinationRectangle.y = y + _offsets[_currentAnimation].y;
       destinationRectangle.w = _sourceRect.w * globals::SPRITE_SCALE;
       destinationRectangle.h = _sourceRect.h * globals::SPRITE_SCALE;

       SDL_Rect sourceRect = _animations[_currentAnimation][_frameIndex];
       view -> drawToSurface(_spriteSheet, &sourceRect, &destinationRectangle);
    }
}