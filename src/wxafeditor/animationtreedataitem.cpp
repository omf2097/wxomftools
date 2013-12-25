#include "animationtreedataitem.h"

AnimationTreeDataItem::AnimationTreeDataItem(sd_bk_anim *animation) : wxTreeItemData() {
    this->sprite = NULL;
    this->animation = animation;
}

AnimationTreeDataItem::AnimationTreeDataItem(sd_sprite *sprite) : wxTreeItemData() {
    this->sprite = sprite;
    this->animation = NULL;
}

AnimationTreeDataItem::AnimationTreeDataItem() : wxTreeItemData() {
    this->sprite = NULL;
    this->animation = NULL;
}

int AnimationTreeDataItem::getType() {
    if(this->sprite != NULL) {
        return SPRITE;
    } else if(this->animation != NULL) {
        return ANIMATION;
    } else {
        return EMPTY;
    }
}

sd_bk_anim* AnimationTreeDataItem::getAnimation() {
    return this->animation;
}

sd_sprite* AnimationTreeDataItem::getSprite() {
    return this->sprite;
}
