#include "animationtreedataitem.h"

AnimationTreeDataItem::AnimationTreeDataItem(sd_animation *animation) : wxTreeItemData() {
    this->sprite = NULL;
    this->animation = animation;
}

AnimationTreeDataItem::AnimationTreeDataItem(sd_sprite *sprite) : wxTreeItemData() {
    this->sprite = sprite;
    this->animation = NULL;
}


int AnimationTreeDataItem::getType() {
    if(this->sprite != NULL) {
        return SPRITE;
    } else {
        return ANIMATION;
    }
}

sd_animation* AnimationTreeDataItem::getAnimation() {
    return this->animation;
}

sd_sprite* AnimationTreeDataItem::getSprite() {
    return this->sprite;
}
